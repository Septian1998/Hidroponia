//library untuk SD Card
#include "FS.h"
#include "SD.h"
#include <SPI.h>

//library untuk DS18b20
#include <OneWire.h>
#include <DallasTemperature.h>

//library untuk dapatkan waktu dari NTP Server
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

//library untuk LCD_I2C
#include <LiquidCrystal_I2C.h>

#define pH_sns 34
#define TDS_sns 35
//#define temp_sns 32

#define ssid "Bang Bud"
#define pass "septian19"
#define address "http://hidroponia-app.herokuapp.com/simpandata"
#define SD_CS 5

unsigned long tempValue = 0, tdsValue = 0, pHValue = 0, avgValuepH;
int Celcius, buf[10], temp;
String strTDS, strpH;

LiquidCrystal_I2C lcd(0x27, 20, 4);

//Menyimpan pembacaan angka di RTC memory
RTC_DATA_ATTR int readingID = 0;

String dataMessage;

#define ONE_WIRE_BUS 21
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperature;

//definisikan NTP Client untuk mendapatkan waktu
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//Variebel untuk menyimpan tanggal dan waktu
String formatedDate;
String dayStamp;
String timeStamp;

void setup()
{
    Serial.begin(115200);
    pinMode(pH_sns, INPUT);
    pinMode(TDS_sns, INPUT);
    //pinMode(temp_sns, INPUT);

    //konek ke Wi-Fi network dengan SSI dan password
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" ");
    Serial.println("WiFi Connected");

    //inisialisasi NTPClient untuk mendapatka waktu
    timeClient.begin();
    timeClient.setTimeOffset(25200);

    //inisialisasi SD Card
    SD.begin(SD_CS);
    if(!SD.begin(SD_CS))
    {
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return;
    }
    Serial.println("Initializing SD card . . .");
    if(!SD.begin(SD_CS))
    {
        Serial.println("ERROR - SD card Initialization failed!");
        return;
    }
    //jika file data.tt tidak ada
    //buat file di SD card dan tulisdata label
    File file = SD.open("/data.txt");
    if(!file)
    {
        Serial.println("File doens't exist");
        Serial.println("Creating file...");
        writeFile(SD, "/data.txt", "Reading ID, Date, Hour, Temperature \r\n");
    }
    else 
    {
        Serial.println("File already exists");  
    }
    file.close();

    //Memulai library DallasTemperature
    sensors.begin();
}

void loop()
{

}

void getReadings()
{
    //baca sensor temperatur
    sensors.requestTemperatures(); 
    temperature = sensors.getTempCByIndex(0); // Temperatur dalam Celsius
    //temperature = sensors.getTempFByIndex(0); // Temperatur dalam Fahrenheit
    Serial.print("Temperature: ");
    Serial.println(temperature);

    //baca sensor suhu
    for (int i = 0; i < 10; i++)
    {
        buf[i] = analogRead(pH_sns);
        delay(30);
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (buf[i] > buf[j])
            {
                temp = buf[i];
                buf[i] = buf[j];
                buf[j] = temp;
            }
        }
    }
    avgValuepH = 0;
    for (int i = 2; i < 8; i++)
    {
        avgValuepH += buf[i];
    }
    avgValuepH = avgValuepH / 6;
    pHValue = (avgValuepH * 3.3) / 4095;
    pHValue = -0.2606 * pHValue + 4.9147; //-5.70 adalah gradien dan 21.34 adalah koefisien kalibrasi
    //Serial.println(pHValue);
}

void getTimeStamp()
{
    while (!timeClient.update())
    {
        timeClient.forceUpdate();
    }
    formatedDate = timeClient.getFormattedDate();
    Serial.println(formatedDate);
    //ekstrak tanggal
    int splitT = formatedDate.indexOf("T");
    dayStamp = formatedDate.substring(0,splitT);
    Serial.println(dayStamp);
    //ekstrak waktu
    timeStamp = formatedDate.substring(splitT+1, formatedDate.length()-1);
    Serial.println(timeStamp);
}

void logSDCard()
{
    dataMessage = String(readingID) + "," + String(dayStamp) + "," + String(timeStamp) + "," + String(temperature) + "\r\n";
    Serial.print("Save data: ");
    Serial.println(dataMessage);
    appendFile(SD, "/data.txt", dataMessage.c_str());
}

// Write to the SD card (DON'T MODIFY THIS FUNCTION)
void writeFile(fs::FS &fs, const char * path, const char * message) 
{
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file)  
    {
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)) 
    {
        Serial.println("File written");
    } 
    else 
    {
        Serial.println("Write failed");
    }
    file.close();
}

// Append data to the SD card (DON'T MODIFY THIS FUNCTION)
void appendFile(fs::FS &fs, const char * path, const char * message) 
{
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file) 
    {
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message))
    {
        Serial.println("Message appended");
    }
    else
    {
        Serial.println("Append failed");
    }
    file.close();
}