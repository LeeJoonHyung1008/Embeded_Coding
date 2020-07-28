#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11

char data = 65;
byte Sstate = 0;
byte Rstate = 0;

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);

void setup()
{
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    if(Sstate == 0)
    {
      Serial.print("Me : ");
      Sstate = 1;
      Rstate = 0;
    }
    
    data = (char)Serial.read();
    mySerial.write(data);
      
    Serial.wrtie(data);
  }
  if(mySerial.available())
  {
    if(Rstate == 0)
    {
      Serial.print("You : ");
      Rstate = 1;
      Sstate = 0;
    }
    
    data = (char)mySerial.read();
    Serial.write(data);
  }
}
