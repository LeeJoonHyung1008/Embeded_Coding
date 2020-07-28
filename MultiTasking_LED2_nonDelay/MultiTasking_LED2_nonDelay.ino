// 2018271166 이준형 학생입니다.

#define LED1  2
#define LED2  3

int ledState = LOW;
int ledState2 = LOW;

long previousMillis = 0;
long previousMillis2 = 0;

long onTime = 200;
long onTime2 = 400;

long offTime = 800;
long offTime2 = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if((ledState == HIGH) && (currentMillis - previousMillis >= onTime))
  {
    ledState = LOW;
    previousMillis = currentMillis;
    digitalWrite(LED1, ledState);
  }
  else if((ledState == LOW) && (currentMillis - previousMillis >= offTime))
  {
    ledState = HIGH;
    previousMillis = currentMillis;
    digitalWrite(LED1, ledState);
  }

   if((ledState2 == HIGH) && (currentMillis - previousMillis2 >= onTime2))
  {
    ledState2 = LOW;
    previousMillis2 = currentMillis;
    digitalWrite(LED2, ledState2);
  }
  else if((ledState2 == LOW) && (currentMillis - previousMillis2 >= offTime2))
  {
    ledState2 = HIGH;
    previousMillis2 = currentMillis;
    digitalWrite(LED2, ledState2);
  }
}
