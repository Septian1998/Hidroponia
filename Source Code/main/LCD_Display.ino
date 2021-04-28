void LCD_Display()
{
    //lcd.clear();
    lcd.setCursor(0, 0 );
    lcd.print("pH  : " + String(pHValue));
    lcd.setCursor(0, 1);
    lcd.print("TDS : -" /*+ String(TDSValue)*/);
    lcd.setCursor(8, 2);
    lcd.write(0);
    lcd.setCursor(9, 2);
    lcd.print("C");
    lcd.setCursor(14, 0);
    lcd.print("|");
    lcd.setCursor(14, 1);
    lcd.print("|");
    lcd.setCursor(15, 1);
    lcd.print("_____");
    lcd.setCursor(15, 0);
    lcd.print(String(timeStamp));
    lcd.setCursor(0, 2);
    lcd.print("Tank: AMix BMix pH");
    lcd.setCursor(6, 3);
    lcd.print(String(tank[Amix]));
    lcd.setCursor(11, 3);
    lcd.print(String(tank[Bmix]));
    lcd.setCursor(16, 3);
    lcd.print(String(tank[pHup]));
}