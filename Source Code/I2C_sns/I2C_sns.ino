

/*

This sketch runs on an ATtiny85 connected to an Arduino Mega running a receiver sketch
This sketch gets distance data from three ultrasonic sensors and transmits it to the Arduino when requested

Andreas Spiess, 2015

*/

#include <TinyWireS.h>       // Requires fork by Rambo with onRequest support
#include <NewPing.h>         // NewPing version 1.7
#include <avr/wdt.h>         // watchdog

#define Amix 0  //Amix
#define Bmix 2  //bmix
#define pHup 1  //pHup

#define Amix_T PB1
#define Amix_E PB1

#define Bmix_T PB3
#define Bmix_E PB3

#define pHup_T PB4
#define pHup_E PB4

#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing SensorAmix (Amix_T, Amix_E, MAX_DISTANCE);  // Define left Sensor
NewPing SensorBmix (Bmix_T, Bmix_E, MAX_DISTANCE);  // Define middle Sensor
NewPing SensorpHup (pHup_T, pHup_E, MAX_DISTANCE);  // Define right Sensor


const int I2CSlaveAddress = 8;      // I2C Address.

int distance[3];                    // Where the Distance is stored (8 bit unsigned)
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
  readDistance();
  wdt_reset();                // feed the watchdog
}

void transmit()
{
  byte hh;
  switch (place) {
    case 0:
      hh = 255;               // start byte
      break;
    case 1:
      hh = distance[Amix];    // Send last recorded distance for current sensor
      break;
    case 2:
      hh = distance[Bmix];    // Send last recorded distance for current sensor
      break;
    case 3:
      hh = distance[pHup];    // Send last recorded distance for current sensor
      break;
  }
  TinyWireS.send(hh);
  place = place + 1;
  if (place > 3) place = 0;
}

void readDistance()
{
  distance[Amix] = SensorAmix.ping_cm();
  delay(20);
  distance[Bmix] = SensorBmix.ping_cm();
  delay(20);
  distance[pHup] = SensorpHup.ping_cm();
  delay(20);
}