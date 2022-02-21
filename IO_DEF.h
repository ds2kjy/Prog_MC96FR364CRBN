

#ifndef _IO_DEF_H_
#define _IO_DEF_H_

#define coderom ((unsigned char volatile code  *) 0x3fa0)	//509 Sector
#define R_Buff_Reg ((unsigned char volatile xdata  *) 0x0270)

	// initialize ports
	//   2 : P23      out pFAN_LED1
	//   3 : P24      out pFAN_LED2
	//   5 : P30      out pPower_On
	//   6 : P31      out pFAN_1
	//   7 : P32      out pFAN_2
	//   8 : P00      out pSCL
	//   9 : P01      out pFAN
	//  10 : P02      out pPOWER_LED
	//  11 : P03      out pLED_EN1
	//  12 : P04      out pFAN_OFF
	//  13 : P05      in  pSENSOR_IN
	//  14 : P06      out pTest1
	//  15 : P07      out pTest2
	//  16 : P10      in  pLow_Batt
	//  17 : P11      in  pFAN_KEY
	//  18 : P12      in  pKEY
	//  19 : P13      in  pVOICE_BUSY
	//  20 : P14      in  pKEY_ADC
	//  21 : P15      out pVOICE_CSB
	//  22 : P16      out pVOICE_CLK
	//  23 : P17      out pVOICE_SDI
	//  24 : P20      out 
	//  25 : P21      out 
	//  26 : P22      out 


//0623수정 진행 
	//   1 : P35      out pFAN_1   //
	//   2 : P34      out pFAN_2  //
	//   3 : P33      out pPower_On
	//   4 : RESETB   in  pReset
	//   5 : P31      ????????????SCL//out pMode_Led1
	//   6 : P30      ????????????SDA//out pMode_Led2
	//   7 : P26      out pPower_Led
	//   8 : P25      out pLed_En
	//   9 : P24      out pFan_Led_1
	//  10 : P23      out pFan_Led_2
	//  11 : P22      in  pKey_Power
	//  12 : P21      in  pKey_Fan
	//  20 : BUZo     out pBuzzer
	//  25 : P03      in pLow_Batt //

#define pFAN_1                P35   
#define pFAN_2                P34   
#define pLow_Batt            (P0&0x8)
#define pPower_On           P33   
#define pReset                 RESETB
#define SCL         		      P31   //out//pulse
#define pFan_En               P30   
#define pPower_Led          P26   
#define pLed_En               P25   
#define pFan_Led_1           P24   
#define pFan_Led_2           P23   
//#define pKey_Power          (P2&4)	//P22   
#define pKey_Fan              (P2&2)	//P21
#define pSensor_In            (P2&1)	//P20      
#define pFan_Off       	  		P15  
#define pKey_Power          (P2&0x80)	//P17   

#define pVoice_Reset	P02
#define pVoice_Data		P04
#define pVoice_Clk		P05
#define pVoice_Cs		P06
#define pBusy			(P1&0x1)//P10


#endif	// _IO_DEF_H_
