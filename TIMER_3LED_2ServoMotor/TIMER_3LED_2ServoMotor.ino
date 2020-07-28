#include <Servo.h>

class tSchedule
{
  int dPIN;
  long onTime;
  long offTime;
  int dState;
  unsigned long pMillis;
  
  public:
  tSchedule(int pin, long onT, long offT);
  void update(unsigned long currentMillis);
};

class SVswp
{
  Servo servo;
  int pos;
  int increment;
  int updateInterval;
  unsigned long lastUpdate;
  
  public:
  SVswp(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update(unsigned long currentMillis);
};

  void SVswp::Update(unsigned long currentMillis)
  {
    if((currentMillis - lastUpdate) > updateInterval)
    {
      lastUpdate = currentMillis;
      pos += increment;
      servo.write(pos);
      if((pos >= 180) || (pos <= 0))
      {
        increment = -increment;
      }
    }
  }

    
tSchedule::tSchedule(int pin, long onT, long offT)
{
  dPIN = pin;
  pinMode(dPIN, OUTPUT);
  onTime = onT;
  offTime = offT;
  dState = LOW;
  pMillis = 0;
}

void tSchedule::update(unsigned long currentMillis)
{
  unsigned long cMillis = currentMillis;
  if((dState == HIGH)&&(cMillis - pMillis >= onTime))
  {
    dState = LOW;
    pMillis = cMillis;
    digitalWrite(dPIN, dState);
  }
  else if((dState == LOW)&&(cMillis - pMillis >= offTime))
  {
    dState = HIGH;
    pMillis = cMillis;
    digitalWrite(dPIN, dState);
  }
}

tSchedule led1(11, 1000, 2000);
tSchedule led2(12, 1500, 1500);
tSchedule led3(13, 2500, 500);

SVswp servo1(25);
SVswp servo2(35);

void setup()
{
  servo1.Attach(9);
  servo2.Attach(10);
  
  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0 = 0;
  OCR0A = 156;
  TCCR0A |= (1<<WGM01);
  TCCR0B |= (1<<CS02) | (1<<CS00);
  TIMSK0 |= (1<<OCIE0A);
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 65535-46875;
  TCCR1B |= (1<<CS12) | (1<<CS10);
  TIMSK1 |= (1<<TOIE1);
  interrupts();
  Serial.begin(9600);
}
int senVal[6] = {0,};
int cntl = 0;
int cnt = 0;

void loop()
{

}

SIGNAL(TIMER0_COMPA_vect)
{
  if(cnt%50 == 0)
  {
    senVal[cntl%6] = analogRead(A0);
    Serial.print(senVal[cntl%6]);
    Serial.print("\t");
    cntl++;
   }
   cnt++;         
}
SIGNAL(TIMER1_OVF_vect)
{
  TCNT1 = 65535 - 46875;
  int sum = 0;
  for(int i=0; i<6; i++)
   { sum += senVal[i]; }
  Serial.print("\t\tavg : ");
  Serial.println(sum/6);
}
