#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Bang Bud";
const char* pass = "septian19";

String serverName = "http://hidroponia-app.herokuapp.com/simpandata";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, pass);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    if((millis() - lastTime) > timerDelay)
    {
        if(WiFi.status() == WL_CONNECTED)
        {
            HTTPClient http;

            String serverPath = serverName + "?field1=27&field2=37&field3=47" ;

            http.begin(serverPath.c_str());

            int httpResponseCode = http.GET();

            if (httpResponseCode>0)
            {
                Serial.print("HTTP Response code: ");
                Serial.println(httpResponseCode);
                String payload = http.getString();
                Serial.println(payload);
            }
            else
            {
                Serial.print("Error code: ");
                Serial.println(httpResponseCode);
            }
            http.end();
        }
        else
        {
            Serial.println("WiFi Disconnected");
        }
        lastTime = millis();
    }
}