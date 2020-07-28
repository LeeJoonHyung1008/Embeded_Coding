#include<EEPROM.h>
unsigned long baseTime;
unsigned long pauseTime;
unsigned long cTime;
char incommingByte = 0;
int sCNT = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  baseTime = pauseTime = 0;
  Serial.println("v is start, p is pause, r is resetTime");
}

void loop() {
  // put your main code here, to run repeatedly:
 static bool pauseFG = 0;
  if(Serial.available() > 0)
  {
    incommingByte = Serial.read();
    switch(incommingByte)
    {
      case 'V':
      case 'v':
        baseTime = getTime();
        pauseFG = 0;
        break;
      case 'p':
        if(!pauseFG)
        {
          pauseTime = printTime(pauseTime);
          Serial.println("PAUSE !!");
          pauseFG = 1;
        }
        break;
      case 'r':
        pauseTime = 0;
        Serial.println("Timer reset !!");
        break;
    }
  }
  switch(incommingByte)
  {
    case 'V':
    case 'v':
      printTime(pauseTime);
      break;
    case 'p':
      break;
    case 'r':
      break;
    case 'm':
      break;
  } 
}

unsigned long printTime(unsigned long pTime)
{
  int Sec;
  int Min;
  int sec100;
  static int oldSec;
  unsigned long temp;
  unsigned long temp2;
  temp = getTime()-baseTime + pTime;
  temp2 = temp/1000;
  sec100 = (temp/10)%100;
  Sec = temp2%60;
  Min = temp2/60;
  if(sec100 != oldSec)
  {
    Serial.print("Present Time (MM:SS) -> \t");
    Serial.print(Min);
    Serial.print(" : ");
    Serial.print(Sec);
    Serial.print(" : ");
    Serial.println(sec100);
  }
  oldSec = sec100;
  cTime = temp;
  return temp;
}
unsigned long getTime()
{
  unsigned long ms_time;
  ms_time = millis();
  return ms_time;
}
