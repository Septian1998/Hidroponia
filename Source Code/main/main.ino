//library untuk SD Card
#include "FS.h"
#include "SD.h"
#include <SPI.h>

//library untuk I2C sensor
//#include <Wire.h>

//library untuk DS18b20
//#include <OneWire.h>
//#include <DallasTemperature.h>

//library untuk dapatkan waktu dari NTP Server dan GET
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <HTTPClient.h>

//library untuk LCD_I2C
#include <LiquidCrystal_I2C.h>

//library untuk Servo
#include <Servo_ESP32.h>

#define pH_sns 35
#define TDS_sns 34
#define TDS_sw 15
//#define temp_sns 32

#define ssid "Halopro"/*"Bang Bud"*/
#define pass "2021proto"/*"septian19"*/
#define SD_CS 5

//Pin Ultrasonic
#define A_TRIG 33
#define A_ECHO 25
#define B_TRIG 26
#define B_ECHO 27
#define pH_TRIG 4
#define pH_ECHO 2

//#define MAX_DISTANCE 400

#define Amix 0  //Amix
#define Bmix 2  //bmix
#define pHup 1  //pHup

//variable pH
float pHValue;
uint16_t valpH[10];
float avgpH, jumlahpH;
float ph_sp= 6;
float ph_error_1, ph_er=0, ph_dError;
float ph_def;

//variable TDS
float TDSValue;
//uint16_t valTDS[10];
//float avgTDS, jumlahTDS;
//float tds_sp= 1175;
//float tds_error_1, tds_er=0, tds_dError;
//float tds_def;

TaskHandle_t TaskFLC;

String address = "http://hidroponia-app.herokuapp.com/api/";

unsigned long lastTime = 0;
unsigned long timerDelay = 60000; //60 detik
unsigned long lastTimeLCD = 0;
unsigned long timerDelayLCD = 1000; //1 detik

//variable suhu
int suhu;

LiquidCrystal_I2C lcd(0x27, 20, 4);

//Menyimpan pembacaan angka di RTC memory
RTC_DATA_ATTR int readingID = 0;

String dataMessage;

//definisikan NTP Client untuk mendapatkan waktu
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//definisikan servo
Servo /*A_MIX, B_MIX,*/ pH_servo;
//float def;

//Variebel untuk menyimpan tanggal dan waktu
String formatedDate;
String dayStamp;
String timeStamp;

byte derajat[] = {0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00};

float Sensor[3];
int tank[3];
int place;

void setup()
{
    //Wire.begin();
    Serial.begin(115200);
    xTaskCreatePinnedToCore(FLC, "TaskFLC", 10000, NULL, 1, &TaskFLC, 0);
    //A_MIX.attach(13);
    //B_MIX.attach(14);
    pH_servo.attach(12);
    pinMode(A_TRIG,OUTPUT);
    pinMode(A_ECHO,INPUT);
    pinMode(B_TRIG,OUTPUT);
    pinMode(B_ECHO,INPUT);
    pinMode(pH_TRIG,OUTPUT);
    pinMode(pH_ECHO,INPUT);
    lcd.begin();
    lcd.backlight();
    lcd.createChar(0, derajat);
    //konek ke Wi-Fi network dengan SSID dan password
    //Serial.print("Connecting to ");
    //Serial.println(ssid);
    WiFi.begin(ssid, pass);
    /*while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" ");
    Serial.println("WiFi Connected");*/

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
    //Serial.println("Initializing SD card . . .");
    if(!SD.begin(SD_CS))
    {
        Serial.println("ERROR - SD card Initialization failed!");
        return;
    }
    //jika file data.txt tidak ada
    //buat file di SD card dan tulisdata label
    File file = SD.open("/data.txt");
    if(!file)
    {
        Serial.println("File doens't exist");
        Serial.println("Creating file...");
        writeFile(SD, "/data.txt", "Reading ID, Date, Hour, pH up Tank, pH \r\n");
    }
    else 
    {
        Serial.println("File already exists");  
    }
    file.close();


}

void FLC(void * pvParameters)
{
    for(;;)
    {
        //Baca Sensor
        get_pH();
        
        ph_er = ph_sp - pHValue;
        
        //tds_error_1 = tds_er;
        //tds_er = tds_sp - TDSValue;
        //tds_dError = tds_er - tds_error_1;

        if(ph_er!=0/*ph_er>=0.5 && ph_er<=(-0.5)*/)
        {
            get_pH();
            
            ph_error_1 = ph_er;
            ph_er = ph_sp - pHValue;
            ph_dError = ph_er - ph_error_1;

            ph_def = fuzzy(ph_er, ph_dError);
            Serial.println(round(ph_def));
            pH_servo.write(round(ph_def));
        }
        else if(ph_er==0/*ph_er<=0.5 && ph_er>=(-0.5)*/)
        {
            for(int dly=0; dly<=180; dly++)
            {   
                pH_servo.write(0);
                delay(1000);
            }
        }
        
        /*float sp= 4.9;
        float error_1, er=0, dError;
        float def;
        getReadings();
        error_1 = er;
        er = sp - pHValue;
        dError = er - error_1;
        Serial.println("error: " + String(er));
        Serial.println("derror: " + String(dError));
        def = fuzzy(er, dError);
        Serial.println(round(def));
        A_MIX.write(round(def));*/
    }
}

void loop()
{   
    getReadings();
    get_pH();
    if((millis() - lastTimeLCD) > timerDelayLCD)
    {
        getTimeStamp();
        LCD_Display();
        lastTimeLCD = millis();
    }
    if((millis() - lastTime) > timerDelay)
    {
        //sendGET();
        logSDCard();
        readingID++;
        lastTime = millis();
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

void get_pH()
{
    //baca sensor pH
    for (int a = 0; a < 10; a++)
    {
        valpH[a] = analogRead(pH_sns);
        delay(30);
    }
    jumlahpH = 0;
    for (int b = 0; b < 10; b++)
    {
        jumlahpH += valpH[b];
    }
    avgpH = (jumlahpH / 10) * 3.3 / 4095 ;
    pHValue = 3.5*avgpH;
    //pHValue = -0.0092 * avgpH  + 28.078; //-0.0092 adalah gradien dan 28.078 adalah koefisien kalibrasi
    //Serial.println(pHValue);
}