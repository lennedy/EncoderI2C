#ifndef CONVERSAO_H
#define CONVERSAO_H

#define DATA_SIZE 1 

class Conversao{
  public:
  long arrayToLong(const uint8_t* c){
    long temp=0;
		for(int i=0; i<DATA_SIZE; i++){
		  temp+=c[i];
			if(i<DATA_SIZE-1)
			  temp<<=8;  
		}
    return temp;
  }

  void longToArray(const long t, uint8_t* c){
//    c[0] = t>>24;
//    c[1] = t>>16;
//    c[2] = t>>8;
    c[3] = t & 0xff;
  }
  
  void intToChar(const int t, uint8_t* c){
    c[0] = t>>8;
    c[1] = t & 0xff;
  }

};

#endif
