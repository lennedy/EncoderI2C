#include <Wire.h>
#include <EncoderI2C.h>

EncoderI2C encoder;

void setup(){  
    Serial.begin(9600);
}

void loop(){
  long l=0;
  Serial.print("Encoder: ");
  l=encoder.getData();
  
  
  Serial.println(l);
  Serial.println("");

  delay(50);
}

