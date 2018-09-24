#ifndef ENCODER_I2C_H
#define ENCODER_I2C_H

//#ifdef AVR_ATtiny85
//	#include <TinyWireS.h>
//#else
#include <Wire.h>
#include <Conversao.h>
//#endif

class EncoderI2C{
	public:
		EncoderI2C(int address=0x26);
		long getData();
	private:
		int ATtinyAddress;
		Conversao conv;
};

#endif
