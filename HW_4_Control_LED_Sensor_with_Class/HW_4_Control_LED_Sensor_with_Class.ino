int led = 3;
int cds = A0;
int brightness = 0;
int fadeAmount = 5;

int sensorPin = A0;
int sensorValue = 0;

class Lee
{
  public:
  Lee(int cds_pin, int Led_Pin);
  private:
  int L_cdsPin;
  int L_sensorValue;
  int L_LedPin;
};

Lee::Lee(int cds_pin, int Led_Pin)
{
  L_cdsPin = cds_pin;
  L_LedPin = Led_Pin;
  pinMode(L_cdsPin, OUTPUT);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue, DEC);
  sensorValue = map(sensorValue, 0, 1024, 255, 0);
  sensorValue = constrain(sensorValue, 255, 0);
  digitalWrite(L_LedPin, sensorValue);           // 어두울수록 LED의 밝기가 밝아진다.
}

Lee LED1(A0, 3);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int cdsValue = analogRead(cds);
  // 측정된 밝기 값를 시리얼 모니터에 출력합니다.
  Serial.print("cds =  ");
  Serial.println(cdsValue);
 
  //map함수와 constrain을 사용하여 조도센서의 밝기 범위를 0~1023에서 0~255로 변경
  cdsValue = map(cdsValue, 0, 1023, 0, 255);
  cdsValue = constrain(cdsValue, 0, 255);
  analogWrite(led,cdsValue);
  delay(200);
}
