//library untuk SD Card
#include "FS.h"
#include "SD.h"
#include <SPI.h>

//library untuk DS18b20
#include <OneWire.h>
#include <DallasTemperature.h>

//library untuk dapatkan waktu dari NTP Server dan GET
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <HTTPClient.h>

//library untuk LCD_I2C
#include <LiquidCrystal_I2C.h>

//library Servo
#include <Servo_ESP32.h>

#define pH_sns 34
#define TDS_sns 35
//#define temp_sns 32

#define ssid "Bang Bud"
#define pass "septian19"
#define SD_CS 5

String address = "http://hidroponia-app.herokuapp.com/simpandata";

unsigned long lastTime = 0;
unsigned long timerDelay = 10000; //10 detik
unsigned long lastTimeLCD = 0;
unsigned long timerDelayLCD = 50000; //10 detik

//variable pH
uint16_t valpH[10];
float avgpH, avgpHValue, pHValue, jumlahpH;

//variable TDS
//uint16_t valTDS[10];
//float avgTDS, avgTDSValue, TDSValue, jumlahTDS;
//String strTDS, strpH;

//variable suhu
float suhu;

LiquidCrystal_I2C lcd(0x27, 20, 4);

//Menyimpan pembacaan angka di RTC memory
RTC_DATA_ATTR int readingID = 0;

String dataMessage;

#define ONE_WIRE_BUS 32
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//definisikan NTP Client untuk mendapatkan waktu
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//definisikan servo
Servo kran1;
float def;

//Variebel untuk menyimpan tanggal dan waktu
String formatedDate;
String dayStamp;
String timeStamp;

void setup()
{
    Serial.begin(115200);
    kran1.attach(13);
    lcd.begin();
    lcd.backlight();
    
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
}

void loop()
{
    getReadings();
    fuzifikasi();
    rule();
    defuzzyfikasi();

    if((millis() - lastTime) > timerDelay)
    {
        sendGET();
        getTimeStamp();
        logSDCard();
        lastTime = millis();
    }
    if((millis() - lastTimeLCD) > timerDelayLCD)
    {
        LCD_Display();
        lastTimeLCD = millis();
    }
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