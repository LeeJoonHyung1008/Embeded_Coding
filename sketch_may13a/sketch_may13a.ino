#define LED1  2
#define LED2  3
#define LED3  4

int count = 0;
int st1 = 1;
int st2 = 1;
int st3 = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(count%1 == 0)
  {
    digitalWrite(LED1, toggle(st1));   // 이 함수가 호출될 때마다 LED1을 점등한다. (1초마다)
  }
  if(count%2 == 0)    // count를 2로 나눈 나머지가 0이 아니면
  {                 // 혹은 count를 2로 나눈 나머지가 1이면 -> if(count%2)
    digitalWrite(LED2, toggle(st2));
  }
  if(count%4 == 0)
  {
    digitalWrite(LED3, toggle(st3));
  }
  count++;
  delay(1000);
}

int toggle(int &state){   // call by address
  if(state == 0)          // return 하든 말든 상관 X
  {
    state = 1;
  }
  else
  {
    state = 0;
  }
  return state;
}
