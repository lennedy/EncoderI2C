#include <Wire.h>
#include <EncoderI2C.h>

EncoderI2C encoder;

void setup(){
    Serial.begin(9600);
}

void loop(){
  long l=0;
  Serial.print("Nº de pulsos: ");
  l=encoder.getPulsos();
  Serial.print(l);
  Serial.println("");
  

  delay(50);
}

