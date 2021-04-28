void getReadings()
{
    //baca sensor jarak dan konversi ke mL
    tank[Amix] = get_tank(A_TRIG, A_ECHO);
    delay(100);
    tank[Bmix] = get_tank(B_TRIG, B_ECHO);
    delay(100);
    tank[pHup] = get_tank(pH_TRIG, pH_ECHO);
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
    pHValue = -0.0092 * avgpH  + 28.078; //-0.0092 adalah gradien dan 28.078 adalah koefisien kalibrasi
    //Serial.println(pHValue);*/

    //baca sensor TDS
    /*digitalWrite(TDS_sw, HIGH);
    analogRead(TDS_sns);
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
    TDSValue = 2.5927 * avgTDS  - 2014.9; // 2.5927 adalah gradien dan 2014.9 adalah koefisien kalibrasi
    digitalWrite(TDS_sw, LOW);*/
}

int get_tank(int trig, int echo)
{
    // bersihkan trigPin
    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    // Menyetel trigPin ke status HIGH selama 10 mikrodetik
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    // Membaca echoPin, mengembalikan waktu tempuh gelombang suara dalam mikrodetik
    long duration = pulseIn(echo, HIGH);

    // Menghitung jarak
    int cm=duration*0.034/2;
    return 100*(7.5-cm);
}