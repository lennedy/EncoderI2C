#include "Conversao.h"
#include "TinyWireS.h"

#define I2C_SLAVE_ADDR  0x26
#define LED_PIN  3

long count=0;
uint8_t array[4];
Conversao conv;

void setup(){
  pinMode(LED_PIN,OUTPUT);
  TinyWireS.begin(I2C_SLAVE_ADDR);
  TinyWireS.onRequest( onI2CRequest );
}
 
void loop(){
  Switch(LED_PIN);
  delay(1000);
  count++;
}

void onI2CRequest(){
	conv.longToArray(count, array);
  TinyWireS.send(array);
}

void Switch(int relay){
    if (digitalRead(relay) == HIGH){ digitalWrite(relay,LOW);}
    else {digitalWrite(relay,HIGH);}
}

