void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;
  float val_float;
  if(Serial.available())
  {
    value = Serial.parseInt();
    val_float = Serial.parseFloat();
    Serial.print("Entered Value : ");
    Serial.print(value);
    Serial.print(val_float);
  }
}
