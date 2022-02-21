#ifndef _DEF_H_
#define _DEF_H_

#define Test_Debug  0		//uart test ÆíÈ÷

#define cli()		do{IE &= ~0x80;}while(0)
#define sei()		do{IE |=  0x80;}while(0)
typedef unsigned char	uchr;
typedef unsigned int  	uint;

typedef struct 
{
    unsigned char   b0	:1;
    unsigned char   b1	:1;
    unsigned char   b2	:1;
    unsigned char   b3	:1;
    unsigned char   b4	:1;
    unsigned char   b5	:1;
    unsigned char   b6	:1;
    unsigned char   b7	:1;
} 
BFIELD;

//typedef union { 
//	unsigned char   Ram_Car;
//	BFIELD          Ram_Bit;
//}TYPE1;


typedef union {
	unsigned char   Ram_Car;
	BFIELD          Ram_Bit;
}TYPE1;

 
typedef union {
	uchr DATA;
	struct {
		unsigned char b0:1;
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
	} BIT;
} SFR;

#define coderom_D  ((unsigned char volatile code  *) 0)


//#define Low_Bat_Cnt_Ini  50
#define pSensor_Cnt_Ini  5

#define Temp_Ini	2010		// 0~4095  

//2010adc : 1.62v //3.3v 

//vout = (Rth/10k+Rth)x5V
//adc = (vout/5)x adc(4096)            //4096 = 12bit


#endif	// _DEF_H_
