void getReadings()
{
    //baca sensor temperatur
    sensors.requestTemperatures(); 
    suhu = sensors.getTempCByIndex(0); // Temperatur dalam Celsius
    
    //temperature = sensors.getTempFByIndex(0); // Temperatur dalam Fahrenheit
    //Serial.print("Temperature: ");
    //Serial.println(temperature);

    distance[Amix] = SensorAmix.ping_cm();
    delay(100);
    distance[Bmix] = SensorBmix.ping_cm();
    delay(100);
    distance[pHup] = SensorpHup.ping_cm();
    delay(100);
    
    //baca sensor pH
    /*for (int a = 0; a < 10; a++)
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
    avgpHValue = (avgpH * 3.3) / 4095;
    pHValue = -0.2606 * avgpHValue  + 4.9147; //-5.70 adalah gradien dan 21.34 adalah koefisien kalibrasi
    //Serial.println(pHValue);

    //baca sensor TDS
    for (int j = 0; j < 10; j++)
    {
        valTDS[j] = analogRead(TDS_sns);
        delay(30);
    }
    jumlahTDS = 0;
    for (int k = 0; k < 10; k++)
    {
        jumlahTDS += valTDS[k];
    }
    avgTDS = jumlahTDS / 10;
    avgTDSValue = (avgTDS * 3.3) / 4095;
    TDSValue = -0.2606 * avgTDSValue  + 4.9147;

    //Baca I2C sensor ultrasonic
    //Serial.print("L");
    while (readTiny(I2CSlaveAddress) < 255)
    {
        Serial.print("WT"); // wait for first byte
    }
    for (place = 0; place < 3; place++)
    {
        dist[place] = readTiny(I2CSlaveAddress);
    }
    for (int i = 0; i < 3; i++)
    {
        Serial.print(dist[i]);
        Serial.print(" ");
    }
    //Serial.println();
    delay(200);*/
}

/*byte readTiny(int address)
{
    byte hh ;
    long entry = millis();
    Wire.requestFrom(address, 1);                  // The TinyWire library only allows for one byte to be requested at a time
    while (Wire.available() == 0 && (millis() - entry) < 100)  Serial.print("W");
    if  (millis() - entry < 100) hh = Wire.read();
    return hh;
}*/