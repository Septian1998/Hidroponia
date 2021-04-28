const int pH_sns = 35;

float pHValue;
uint16_t valpH[10];
float avgpH, jumlahpH;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(pH_sns, INPUT);
  //pinMode(15, OUTPUT);
  //digitalWrite(15, HIGH);
}

void loop() {
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
    avgpH = jumlahpH / 10;
    pHValue = 0.0103 * avgpH  - 9.1926; //-0.0092 adalah gradien dan 28.078 adalah koefisien kalibrasi
    Serial.println(pHValue);
}
