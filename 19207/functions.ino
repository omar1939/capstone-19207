void servoup() {

s1.write(180);
delay(500);

}

void servodown() {

s1.write(0);
delay(500);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SendMessage1()
{
  //Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(200);
  //Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(200);
  String SMS = "gas leakage detected";    // ---------------------------------------------------------->>>>>>>>>>>>>>>>>   the message 
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(200);
  _buffer = _readSerial();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SendMessage2()
{
  //Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(200);
  //Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(200);
  String SMS = "smoke detected,potential fire"; //  ---------------------------------------------------------->>>>>>>>>>>>>>>>>   the message 
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(200);
  _buffer = _readSerial();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

String _readSerial() {
  _timeout = 0;
  while  (!sim.available() && _timeout < 12000  )
  {
    delay(13);
    _timeout++;
  }
  if (sim.available()) {
    return sim.readString();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void callNumber() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
  _buffer = _readSerial();
  Serial.println(_buffer);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

