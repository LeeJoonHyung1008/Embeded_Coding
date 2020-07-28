// 2018271166 이준형 학생입니다.

class tSchedule
{
  // 변수 선언
  int dPIN;
  long onTime;
  long offTime;
  int dState;
  unsigned long pMillis;
  public:
  tSchedule(int pin, long onT, long offT);  // 3개의 Argument를 받는 생성자.
  void update();  // 연결된 LED의 현재(cMillis) 시간, 이전(pMillis) 시간을 통해 onT과 offT를 비교하여 LED를 점등하는 함수이다.
};

void tSchedule::update()
{
  unsigned long cMillis = millis();
  if((dState == HIGH) && (cMillis - pMillis >= onTime))
  {
    dState = LOW;
    pMillis = cMillis;
    digitalWrite(dPIN, dState);
  }
  else if((dState == LOW) && (cMillis - pMillis >= offTime))
  {
    dState = HIGH;
    pMillis = cMillis;
    digitalWrite(dPIN, dState);
  }
}

tSchedule::tSchedule(int pin, long onT, long offT)   // tSchedule의 3개의 Argument를 받는 생성자이다.
{                                                    // 생성자를 하나 선언하였으므로 default 생성자는 만들어지지 않는다.
  dPIN = pin;
  pinMode(dPIN, OUTPUT);
  onTime = onT;
  offTime = offT;
  dState = LOW;
  pMillis = 0;
}

tSchedule LED1(2, 200, 800);  // LED1을 2번 pin에 연결하였고, ON : 200, OFF : 800
tSchedule LED2(3, 400, 300);  // LED2을 3번 pin에 연결하였고, ON : 400, OFF : 300
tSchedule LED3(4, 700, 500);  // LED3을 4번 pin에 연결하였고, ON : 700, OFF : 500

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:  
  unsigned long currentMillis = millis();
  LED1.update();
  LED2.update();
  LED3.update();
}
