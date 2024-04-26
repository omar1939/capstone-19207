#include<Servo.h>;   
 Servo s1 ;
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define BUZZER1 3
#define BUZZER2 4
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SoftwareSerial.h> ;
SoftwareSerial sim(10, 11);
int _timeout;
String _buffer;
String number = "+201281504523"; //-> change with your number
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() 
{
//delay(7000); //delay for 7 seconds to make sure the modules get the signal
  Serial.begin(9600);
  _buffer.reserve(50);
  Serial.println("System Started...");
  sim.begin(9600);
  delay(1000);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  pinMode(BUZZER1 , OUTPUT);
  pinMode(BUZZER2 , OUTPUT);
  s1.attach(6);



  Serial.begin(9600);
}

void loop() 
{
  int gassensor = analogRead(A0);
  Serial.println(gassensor);
 
  int smoke = analogRead(A1);
  Serial.println(smoke);
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  ---------------------------------------------------------->>>>>>>>>>>>>>>>>   the gaseos sensor
  if (gassensor > 450)
  {
    servoup();

   SendMessage1();
   delay(3000);
    callNumber();

digitalWrite(BUZZER1, HIGH ) ;
digitalWrite(BUZZER2, HIGH ) ;
    delay(70000);

  }


  
  else if (gassensor < 450)
  {
   
    servodown();

       }
  delay(1000);
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //---------------------------------------------------------->>>>>>>>>>>>>>>>>   the smoke sensor
if (smoke > 400)
  {
    SendMessage2();
delay(120000);

   }
  else if (smoke < 400)
  {
      digitalWrite(BUZZER1, LOW ) ;
     digitalWrite(BUZZER2, LOW ) ;

  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
























} 
