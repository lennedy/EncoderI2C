#ifndef CONVERSAO_H
#define CONVERSAO_H

#define DATA_SIZE 4 

class Conversao{
  public:
  long arrayToLong(const uint8_t* c){
    unsigned long temp=0;
 		for(int i=DATA_SIZE-1; i>=0; i--){
		  temp+=(unsigned long)c[i];
			if(i>0)
			  temp<<=8;  
		}
//  temp = (long)c[0];
    return (long)temp;
  }

  void longToArray(const long t, uint8_t* c){
    c[0] = t>>24;
    c[1] = t>>16;
    c[2] = t>>8;
    c[3] = t & 0xff;
  }
  
  void intToChar(const int t, uint8_t* c){
    c[0] = t>>8;
    c[1] = t & 0xff;
  }

};

#endif
