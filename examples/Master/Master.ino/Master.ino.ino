#include <Wire.h>
#include <EncoderI2C.h>

EncoderI2C encoder;

void setup(){
    Serial.begin(9600);
}

void loop(){
  long l=0;
  float a=0;
  
  Serial.print("Pulsos e Ang: ");
  l=encoder.getPulsos();
  a=encoder.getAngulo();
  Serial.print(l);
  Serial.print("; ");
  Serial.println(l);


  delay(500);
}

