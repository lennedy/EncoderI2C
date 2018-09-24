#include <Wire.h>
#include <EncoderI2C.h>

EncoderI2C encoder;

void setup(){  
    Serial.begin(9600);
}

void loop(){
  long l=0;
  l=encoder.getData();
  
  Serial.print("Encoder: ");
  Serial.println(l);
  Serial.println("");

  delay(1000);
}

