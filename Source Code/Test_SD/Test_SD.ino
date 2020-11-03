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

//definidikan opsi deep sleep
uint64_t uS_TO_S_FACTOR = 1000000; //faktor konversi untuk micro seconds ke seconds
//tidur selama 1 menit = 60 seconds
uint16_t TIME_TO_SLEEP = 60;

const char* ssid = "Bang Bud";
const char* pass = "septian19";

#define SD_CS 5

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

    // Enable Timer wake_up
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

    // Start the DallasTemperature library
    sensors.begin(); 

    getReadings();
    getTimeStamp();
    logSDCard();
  
    // Increment readingID on every new reading
    readingID++;
  
    // Start deep sleep
    Serial.println("DONE! Going to sleep now.");
    esp_deep_sleep_start();
}

void loop()
{
    
}

void getReadings()
{
    sensors.requestTemperatures(); 
    temperature = sensors.getTempCByIndex(0); // Temperatur dalam Celsius
    //temperature = sensors.getTempFByIndex(0); // Temperatur dalam Fahrenheit
    Serial.print("Temperature: ");
    Serial.println(temperature);
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