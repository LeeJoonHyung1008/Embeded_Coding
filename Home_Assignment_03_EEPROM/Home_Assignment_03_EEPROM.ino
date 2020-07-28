// 2018271166 이준형 학생입니다.
#include<EEPROM.h>

union{
  float fdata;
  char cdata[10]; 
}fDATA;

void setup()
{   
  Serial.begin(9600);   
  pinMode(3, INPUT); 
} 
 
void loop()  
{   
  static int time, minute, second_10, second_1, ms_10, ms_1;  // 1 Byte씩 불러와야 하므로 시간에 대한 변수들을 선언하였습니다. 
  int SW;   // SW의 입력을 받을 변수를 선언합니다. 이 값이 1이면 SW가 눌린 것입니다.
  char input_char;  // 'v'나 'V'를 입력하기 위해 선언하였습니다.
  float data;  // float형의 변수를 선언하였습니다.
  while(1)
  {     
    SW = digitalRead(3);    // 3번 pin의 값을 SW에 저장합니다.
    input_char = Serial.read(); // Serial 모니터에 입력된 문자를 input_char에 저장합니다.
    time = millis();    // millis() 함수를 통해 현재 시간을 측정합니다.
    minute = time/60000;  // 이 값을 60000으로 나눈 값이 '분' 입니다.
    second_10 = time/10000; // 이 값을 10000으로 나눈 값이 '초'의 10의 자리수 입니다.
    second_1 = time/1000; // 이 값을 1000으로 나눈 값이 '초'의 1의 자리수 입니다.
    ms_10 = time/100; // 이 값을 100으로 나눈 값이 'milli sec'의 10의 자리수 입니다.
    ms_1 = time/10; // 이 값을 10으로 나눈 값이 'milli sec'의 1의 자리수 입니다.
 
    if(second_10 >= 6)  // 60초가 되면 이를 초기화 해줍니다.
    second_10=second_10%6;
    if(second_1 >= 10)  // 10초가 되면 이를 초기화 해줍니다.
    second_1 = second_1%10;
    if(ms_10 >= 10) // ms가 10이 되면 이를 초기화 해줍니다.
    ms_10 = ms_10%10;
    if(ms_1 >= 10)  // ms가 1이 되면 이를 초기화 해줍니다.
    ms_1 = ms_1%10;
    Serial.print("현재 시간 : " );
    Serial.print(minute);
    Serial.print(":");
    Serial.print(second_10);
    Serial.print(second_1);
    Serial.print(":");
    Serial.print(ms_10);
    Serial.print(ms_1);
    Serial.print("\n");
    Serial.println(SW);

    if(SW==1)     // Switch를 누르고 있는지 확인하고, SW가 눌렸으면 이 조건문이 실행됩니다.
    {
      fDATA.cdata[8]=minute;    // 분에 해당하는 값을 fDATA.cdata의 8~9에 저장합니다.
      fDATA.cdata[6]=second_10; // 초의 10의 자리수에 해당하는 값을 fDATA.cdata의 6~7에 저장합니다.
      fDATA.cdata[4]=second_1;  // 초의 1의 자리수에 해당하는 값을 fDATA.cdata의 4~5에 저장합니다.
      fDATA.cdata[2]=ms_10;     // milli sec의 10의 자리수에 해당하는 값을 fDATA.cdata의 2~3에 저장합니다.
      fDATA.cdata[0]=ms_1;      // milli sec의 1의 자리수에 해당하는 값을 fDATA.cdata의 0~1에 저장합니다.
      
      EEPROM.write(0,fDATA.cdata[8]); // 이를 Byte 단위로 쪼개서 0부터 fDATA.cdata[8~0]를 역순으로 저장합니다.
      EEPROM.write(2,fDATA.cdata[6]);
      EEPROM.write(4,fDATA.cdata[4]);
      EEPROM.write(6,fDATA.cdata[2]);
      EEPROM.write(8,fDATA.cdata[0]);
      Serial.println(SW);             // 스위치의 현재 값을 출력합니다.
      delay(2000);      
    }
    
     switch(input_char)
    {
      case 'v':
      case 'V':
      fDATA.cdata[8] =  EEPROM.read(0); // EEPROM에 저장된 값들을 불러옵니다.
      fDATA.cdata[6] =  EEPROM.read(2);
      fDATA.cdata[4] =  EEPROM.read(4);
      fDATA.cdata[2] =  EEPROM.read(6); 
      fDATA.cdata[0] =  EEPROM.read(8);
      Serial.print(fDATA.cdata[8]);     // 그리고 해당 값들을 출력합니다. (분)
      Serial.print(":");
      Serial.print(fDATA.cdata[6]);     // (초의 10의 자리수)
      Serial.print(fDATA.cdata[4]);     // (초의 1의 자리수)
      Serial.print(":");
      Serial.print(fDATA.cdata[2]);     // (milli sec의 10의 자리수)
      Serial.print(fDATA.cdata[0]);     // (milli sec의 1의 자리수)
      delay(7000);          
      break;            
    }  
} 
} 
 
 
