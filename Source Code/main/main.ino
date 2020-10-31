#include <WiFi.h>
#include <HTTPClient.h>

#define pH_sns 34
#define TDS_sns 35
#define temp_sns 32

#define ssid "Bang Bud"
#define pass "septian19"
#define address "http://hidroponia-app.herokuapp.com/simpandata"

unsigned long tempValue = 0, tdsValue = 0, phValue = 0, avgphValue;
int Celcius, buf[10];
String strTDS, strpH;

void setup()
{
    pinMode(pH_sns, INPUT);
    pinMode(TDS_sns, INPUT);
    pinMode(temp_sns, INPUT);
}