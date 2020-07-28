void setup() {
  // put your setup code here, to run once:
  Serial.setTimeout(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte incommingByte = 0;
  char inputdata[4] = "";
  int len = 4;
  incommingByte = Serial.readBytes(inputdata,len);
  Serial.print("Received Byte : ");
  Serial.print(incommingByte);
  Serial.print(",\tReceived data : ");
  Serial.print(inputdata);
  Serial.print(",\tlength");
  Serial.println(len);
  Serial.flush();
  Serial.println("flushed");
}
