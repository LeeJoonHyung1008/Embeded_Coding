// 2018271166 이준형 학생입니다.

int sensorPin = A0;
int sensorValue = 0;

class Lee
{
  public:
  Lee(int pin);
  void update();
  private:
  int L_Pin;
  int L_sensorValue;
  int L_brightness;
};

Lee::Lee(int pin)
{
  L_Pin = pin;
  pinMode(L_Pin, OUTPUT);
}

void Lee::update()
{
  L_sensorValue = analogRead(sensorPin);
  Serial.println(L_sensorValue, DEC);
  L_brightness = map(L_sensorValue, 0, 1023, 255, 0);
  L_brightness = constrain(L_sensorValue, 255, 0);
  analogWrite(L_Pin, L_brightness);           // 어두울수록 LED의 밝기가 밝아진다.
}

Lee LED1(2);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  LED1.update();
}
