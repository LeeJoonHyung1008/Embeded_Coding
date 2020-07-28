void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte incommingByte = 0;
  char inputdata[10] = "";
  char last = 'q'; 
  int len = 10;

  incommingByte = Serial.readBytesUntil(last, inputdata, len);
  Serial.print("Received byte : ");
  Serial.print(incommingByte);
  Serial.print(",\tReceived data : ");
  Serial.print(inputdata);
  Serial.print(",\tlength");
  Serial.println(len);
  Serial.flush();
  Serial.println("Flushed");
}
