#define LED1  2
#define LED2  3
#define LED3  4

int ledState = LOW;
long previousMillis = 0;
long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

      digitalWrite(LED1, ledState);
  }
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
