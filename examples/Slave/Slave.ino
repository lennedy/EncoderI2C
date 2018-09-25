//#include "Conversao.h"
#include "TinyWireS.h"

#define RIGHT_ENCODER_ADDR  0x26
#define LEFT_ENCODER_ADDR  0x27
#define LED_PIN       5
#define CONTADOR_PIN  1
#define SENTIDO_PIN   4
#define ADDR_PIN      3

volatile long count=-1000;
volatile uint8_t array[4];
volatile uint8_t numByte=0;
//Conversao conv;

void setup(){
  pinMode(LED_PIN,OUTPUT);
  pinMode(CONTADOR_PIN,INPUT);
  pinMode(SENTIDO_PIN,INPUT);
  pinMode(ADDR_PIN,INPUT);
  
  if(digitalRead(ADDR_PIN) == HIGH){
    TinyWireS.begin(RIGHT_ENCODER_ADDR);
  }
  else{
    TinyWireS.begin(LEFT_ENCODER_ADDR);
  }
  
  TinyWireS.onRequest( onI2CRequest );
  TinyWireS.onReceive(receiveEvent);
}
 
void loop(){
  
  //delay(100);
  if(pinEdgeHigh()){
    Switch(LED_PIN);
    if(digitalRead(SENTIDO_PIN))
      count++;
    else
      count--;
  }
}

bool pinEdgeHigh(){
  static int valPin=0;
  static int valPinLast=0;
  valPin = digitalRead(CONTADOR_PIN);
  if(valPin != valPinLast){
    if(valPin == HIGH){
      valPinLast= valPin;
      return true;
    }
   }
   valPinLast= valPin;
   return false;
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

