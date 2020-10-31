const int potPin = 34;

// variable for storing the potentiometer value
int potValue = 0;
float voltValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);
  voltValue = (potValue * 3.3) / 4095;
  Serial.print("ADC :");
  Serial.println(potValue);
  Serial.print("Volt :");
  Serial.println(voltValue);
  delay(500);
}