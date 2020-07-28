void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long us_time;
  unsigned long ms_time;

  us_time = micros();
  ms_time = millis();
  Serial.println("Time Test\n");
  Serial.println("MS : ");
  Serial.println(ms_time);
  Serial.println("uS : ");
  Serial.println(us_time);
  delay(1000);
}
