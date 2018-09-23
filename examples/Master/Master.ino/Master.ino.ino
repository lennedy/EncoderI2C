#include <Wire.h>

int selection=0;
int ATtinyAddress=0x26;
 
void setup(){
    Wire.begin();
    Serial.begin(9600);
//    PrintMenu();
}

void loop(){
  Wire.requestFrom(ATtinyAddress, 1);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    int c = Wire.read(); // receive a byte as character
    Serial.println(c);         // print the character
  }

  delay(500);
}
