#include <EEPROM.h>

#define debug 0

union EFDATA{
  float fdata;
  byte bdata[4];
};
int FLAG = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int menu = 0;
  if(FLAG == 0)
  {
    printMenu();
    FLAG = 1;
  }
  if(Serial.available())
  {
    menu = Serial.parseInt();
    switch (menu)
    {
      case 1:
        saveFloat2Rom();
        FLAG = 0;
        break;
      case 2:
        readFloatRom();
        FLAG = 0;
        break;
      default:
        Serial.println("Not matched input");
        break;
    }
  }
}

void printMenu()
{
  Serial.println("This is EEPROM control program. \n Select a menu on the following list");
  Serial.println("1. Write a float data to EERPOM with the address");
  Serial.println("2. Read and print a float data to be read from EEPROM");
}

void saveFloat2Rom()
{
  Serial.println("Enter a float number and an address of EEPROM to save data in...");
  Serial.print("Enter a number : ");
  while(!Serial.available());
  float number = Serial.parseFloat();
  Serial.print("Enter an address to save data : ");
  while(!Serial.available());
  int address = Serial.parseInt();
  Serial.print("Th Entered number : ");
  Serial.print(number);
  writeFloat(address, number);
}

void readFloatRom()
{
  Serial.println("Enter an EEPROM address to read a float data from : ");
  while(!Serial.available());
  int address = Serial.parseInt();
  float number = readFloat(address);
  Serial.print("The saved data in the address ");
  Serial.print(address);
  Serial.print(" : ");
  Serial.println(number);
}

float readFloat(int addr)
{
  union EFDATA temp;
  for(int i=0; i<4; i++)
  {
    temp.bdata[i] = EEPROM.read(addr + i);
#if debug ==1
  Serial.print(i);
  Serial.print("-th saved data is ");
  Serial.print(temp.bdata[i]);
  Serial.print(" in address ");
  Serial.print(addr + i);
#endif  
  }
  Serial.println(temp.fdata);
  return temp.fdata;  
}

void writeFloat(int addr, float data)
{
  union EFDATA temp;
  temp.fdata = data;
  for (int i=0; i<4; i++)
  {
    EEPROM.write(addr + i, temp.bdata[i]);
#if debug ==1
  Serial.print(i);
  Serial.print("-th saved data is ");
  Serial.print(temp.bdata[i]);
  Serial.print(" in address ");
  Serial.println(addr+i);
#endif
  }
}
