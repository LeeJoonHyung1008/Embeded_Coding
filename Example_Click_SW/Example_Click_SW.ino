#define SW  2
#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(SW, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char SWcnt = 0;
  SWcnt = CHK_SW1();
  if(SWcnt > 0)
  {
    switch(SWcnt)
    {
      case 3:
      Serial.println("3 clicks !");
      break;
      case 2:
      Serial.println("2 clicks !");
      break;
      case 10:
      Serial.println("Hold !");
      break;
      case 1:
      Serial.println("1 clicks !");
      break;
    }
  }
}

unsigned char CHK_SW1()
{
  unsigned char CNT = 0;
  bool CHK, old, on;
  on = 1;
  unsigned long sTime, eTime;
  unsigned long sCHK = 0;
  old = CHK = digitalRead(SW);
  sTime = eTime = millis();

  if(!CHK)
  {
    digitalWrite(LED, HIGH);
    while((eTime - sTime) < 1000)
    {
      CHK = digitalRead(SW);
      on = on&&!CHK;
      if((CHK > 0) && (old != CHK) && CNT < 3)
      {
        CNT++;
      }
      delay(50);
      old = CHK;
      eTime = millis();
    }
    if(on > 0)
    {
      CNT = 10;
    }
  }
  digitalWrite(LED, LOW);
  return CNT;
}
