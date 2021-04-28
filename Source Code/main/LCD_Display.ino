void LCD_Display()
{
    //lcd.clear();
    lcd.setCursor(0, 0 );
    lcd.print("pH  : " + String(pHValue));
    lcd.setCursor(0, 1);
    lcd.print("TDS : " + String(TDSValue));
    lcd.setCursor(0, 2);
    lcd.print("Suhu: " + String(suhu));
    lcd.setCursor(8, 2);
    lcd.write(0);
    lcd.setCursor(9, 2);
    lcd.print("C");
    lcd.setCursor(14, 0);
    lcd.print("|");
    lcd.setCursor(14, 1);
    lcd.print("|");
    lcd.setCursor(14, 2);
    lcd.print("|");
    lcd.setCursor(15, 2);
    lcd.print("_____");
    lcd.setCursor(15, 1);
    lcd.print(String(timeStamp));
    lcd.setCursor(6, 3);
    lcd.print("OTOMATIS");
}