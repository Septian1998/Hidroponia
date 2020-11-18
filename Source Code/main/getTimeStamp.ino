void getTimeStamp()
{
    while (!timeClient.update())
    {
        timeClient.forceUpdate();
    }
    formatedDate = timeClient.getFormattedDate();
    Serial.println(formatedDate);
    //ekstrak tanggal
    int splitT = formatedDate.indexOf("T");
    dayStamp = formatedDate.substring(0,splitT);
    Serial.println(dayStamp);
    //ekstrak waktu
    timeStamp = formatedDate.substring(splitT+1, formatedDate.length()-1);
    Serial.println(timeStamp);
}