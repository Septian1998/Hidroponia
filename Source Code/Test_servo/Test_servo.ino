#include <Servo_ESP32.h>

static const int servoPin = 14;
int pos = 0;

Servo servo1;

void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin);
}

void loop() {
//    while (Serial.available() != 0) {
//    int val = Serial.parseInt();
//    Serial.println(val);
//    servo1.write(val);
//    delay(5);
    for(int posDegrees = 0; posDegrees <= 90; posDegrees++) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
delay(2000);
    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
}
