void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char incommingByte = 0;

  if(Serial.available() > 0)
  {
    incommingByte = Serial.read();
    Serial.print("I received : ");
    Serial.print(incommingByte);
    Serial.print(", ASCII : ");
    Serial.println(incommingByte, DEC);
  }
}
