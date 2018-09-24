#include "EncoderI2C.h"

EncoderI2C::EncoderI2C(int address){
	Wire.begin();
	ATtinyAddress= address;
}

long EncoderI2C::getData(){
	int i=0;
	uint8_t byteArray[DATA_SIZE];
	Wire.requestFrom(ATtinyAddress, DATA_SIZE);

  while (Wire.available()) { 
		if(i<DATA_SIZE){
		  byteArray[i] = Wire.read(); 
		}
		else{
			break;
		}
		i++;
  }

	return conv.arrayToLong(byteArray);
}
