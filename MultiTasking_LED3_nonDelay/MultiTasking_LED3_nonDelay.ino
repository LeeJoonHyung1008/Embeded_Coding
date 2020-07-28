#define LED1  2
#define LED2  3
#define LED3  4

int ledState = LOW;
int ledState2 = LOW;
int ledState3 = LOW;

long previousMillis = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;

long onTime = 1000;
long onTime2 = 1500;
long onTime3 = 2500;

long offTime = 2000;
long offTime2 = 1500;
long offTime3 = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
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

   if((ledState3 == HIGH) && (currentMillis - previousMillis3 >= onTime3))
  {
    ledState3 = LOW;
    previousMillis3 = currentMillis;
    digitalWrite(LED3, ledState3);
  }
  else if((ledState3 == LOW) && (currentMillis - previousMillis3 >= offTime3))
  {
    ledState3 = HIGH;
    previousMillis3 = currentMillis;
    digitalWrite(LED3, ledState3);
  }
}
