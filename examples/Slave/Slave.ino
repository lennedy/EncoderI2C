//#include "Conversao.h"
#include "TinyWireS.h"

#define I2C_SLAVE_ADDR  0x26
#define LED_PIN  3

volatile long count=-1000;
volatile uint8_t array[4];
volatile uint8_t numByte=0;
//Conversao conv;

void setup(){
  pinMode(LED_PIN,OUTPUT);
  TinyWireS.begin(I2C_SLAVE_ADDR);
  TinyWireS.onRequest( onI2CRequest );
  TinyWireS.onReceive(receiveEvent);
}
 
void loop(){
  Switch(LED_PIN);
  delay(100);
  count++;
}

void receiveEvent(uint8_t b){
  while(TinyWireS.available()){
    numByte = TinyWireS.receive();
  }
}

void onI2CRequest(){
  
//	conv.longToArray(count, array);
  array[0] = count;
  array[1] = count>>8; 
  array[2] = count>>16;
  array[3] = count>>24;
  TinyWireS.send(array[numByte]);

}

void Switch(int relay){
    if (digitalRead(relay) == HIGH){ digitalWrite(relay,LOW);}
    else {digitalWrite(relay,HIGH);}
}

