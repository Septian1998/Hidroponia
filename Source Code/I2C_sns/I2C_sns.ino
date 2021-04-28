#include <TinyWireS.h>       // Requires fork by Rambo with onRequest support
//#include <NewPing.h>         // NewPing version 1.7
#include <avr/wdt.h>         // watchdog

#define tds 1  //Amix
#define ph 0  //pHup

#define tds_sns PB3
#define ph_sns PB4

#define SW_Sensors PB1

//variable pH
uint16_t valpH[10];
float avgpH, avgpHValue, jumlahpH;

//variable TDS
uint16_t valTDS[10];
float avgTDS, jumlahTDS;

/*#define Bmix 2  //bmix

#define Amix_T PB1
#define Amix_E PB1

#define Bmix_T PB3
#define Bmix_E PB3

#define pHup_T PB4
#define pHup_E PB4

#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing SensorAmix (Amix_T, Amix_E, MAX_DISTANCE);  // Define left Sensor
NewPing SensorBmix (Bmix_T, Bmix_E, MAX_DISTANCE);  // Define middle Sensor
NewPing SensorpHup (pHup_T, pHup_E, MAX_DISTANCE);  // Define right Sensor*/

const int I2CSlaveAddress = 8;      // I2C Address.

int sensor[2];                    // Where the sensor is stored (8 bit unsigned)
int place = 0;
unsigned long start;

void setup()
{
  TinyWireS.begin(I2CSlaveAddress);      // Begin I2C Communication
  TinyWireS.onRequest(transmit);         // When requested, call function transmit()
  wdt_enable(WDTO_500MS);     // Watchdog
}

void loop()
{
  readSensors();
  wdt_reset();                // feed the watchdog
}

void transmit()
{
  byte hh;
  switch (place)
  {
    case 0:
      hh = 255;               // start byte
      break;
    case 1:
      hh = sensor[ph];    // Send last recorded distance for current sensor
      break;
    case 2:
      hh = sensor[tds];    // Send last recorded distance for current sensor
      break;
  }
  TinyWireS.send(hh);
  place = place + 1;
  if (place > 2) place = 0;
}

void readSensors()
{
  digitalWrite(SW_Sensors, HIGH);
  for (int a = 0; a < 10; a++)
    {
        valpH[a] = analogRead(ph_sns);
        delay(30);
    }
    jumlahpH = 0;
    for (int b = 0; b < 10; b++)
    {
        jumlahpH += valpH[b];
    }
    avgpH = jumlahpH / 10;
    avgpHValue = (avgpH * 5) / 1024;
    sensor[ph] = (-0.2606 * avgpHValue) + 4.9147; //-0.2606 adalah gradien dan 4.9147 adalah koefisien kalibrasi
    //Serial.println(pHValue);
    delay(20);

    digitalWrite(SW_Sensors, LOW);
    for (int j = 0; j < 10; j++)
    {
        valTDS[j] = analogRead(tds_sns);
        delay(30);
    }
    jumlahTDS = 0;
    for (int k = 0; k < 10; k++)
    {
        jumlahTDS += valTDS[k];
    }
    avgTDS = jumlahTDS / 10;
    sensor[tds] = (0.3417 * avgTDS) + 281.08; //0.3417 adalah gradien dan 281.08 adalah koefisien kalibrasi
    delay(20);
}

/*void readSensors()
{
  digitalWrite(SW_Sensors, HIGH);
  for (int a = 0; a < 10; a++)
    {
        valpH[a] = analogRead(ph_sns);
        delay(30);
    }
    jumlahpH = 0;
    for (int b = 0; b < 10; b++)
    {
        jumlahpH += valpH[b];
    }
    avgpH = jumlahpH / 10;
    avgpHValue = (avgpH * 5) / 1024;
    sensor[ph] = (-0.2606 * avgpHValue) + 4.9147; //-0.2606 adalah gradien dan 4.9147 adalah koefisien kalibrasi
    //Serial.println(pHValue);
    delay(20);

    digitalWrite(SW_Sensors, LOW);
    for (int j = 0; j < 10; j++)
    {
        valTDS[j] = analogRead(tds_sns);
        delay(30);
    }
    jumlahTDS = 0;
    for (int k = 0; k < 10; k++)
    {
        jumlahTDS += valTDS[k];
    }
    avgTDS = jumlahTDS / 10;
    sensor[tds] = (0.3417 * avgTDS) + 281.08; //0.3417 adalah gradien dan 281.08 adalah koefisien kalibrasi
    delay(20);
}*/