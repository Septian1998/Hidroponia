void logSDCard()
{
    dataMessage = String(readingID) + "," + String(dayStamp) + "," + String(timeStamp) + "," + String(suhu) + "\r\n";
    Serial.print("Save data: ");
    Serial.println(dataMessage);
    appendFile(SD, "/data.txt", dataMessage.c_str());
}