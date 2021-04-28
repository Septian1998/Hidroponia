const int potPin = 35;


// variable for storing the potentiometer value
int potValue = 0;
float voltValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(potPin, INPUT);
  //pinMode(15, OUTPUT);
  //digitalWrite(15, HIGH);
}

void loop() {
  // Reading potentiometer value
//  digitalWrite(15, HIGH);
//  analogRead(potValue);
  potValue = analogRead(potPin);
  voltValue = (potValue * 3.3) / 4095;
//  digitalWrite(15, LOW);
  Serial.print("ADC :");
  Serial.println(potValue);
  Serial.print("Volt :");
  Serial.println(voltValue);
  delay(1000);
}
