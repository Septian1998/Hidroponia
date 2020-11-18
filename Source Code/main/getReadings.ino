void getReadings()
{
    //baca sensor temperatur
    sensors.requestTemperatures(); 
    suhu = sensors.getTempCByIndex(0); // Temperatur dalam Celsius
    //temperature = sensors.getTempFByIndex(0); // Temperatur dalam Fahrenheit
    //Serial.print("Temperature: ");
    //Serial.println(temperature);

    //baca sensor pH
    for (int a = 0; a < 10; a++)
    {
        valpH[a] = analogRead(pH_sns);
        delay(30);
    }
    for (int b = 0; b < 10; b++)
    {
        jumlahpH += valpH[b];
    }
    avgpH = jumlahpH / 10;
    avgpHValue = (avgpH * 3.3) / 4095;
    pHValue = -0.2606 * avgpHValue  + 4.9147; //-5.70 adalah gradien dan 21.34 adalah koefisien kalibrasi
    //Serial.println(pHValue);

    //baca sensor TDS
    //for (int j = 0; j < 10; j++)
    //{
        //valTDS[j] = analogRead(TDS_sns);
        //delay(30);
    //}
    //for (int k = 0; k < 10; k++)
    //{
        //jumlahTDS += valTDS[k];
    //}
    //avgTDS = jumlahTDS / 10;
    //avgTDSValue = (avgTDS * 3.3) / 4095;
    //TDSValue = -0.2606 * avgTDSValue  + 4.9147;
}