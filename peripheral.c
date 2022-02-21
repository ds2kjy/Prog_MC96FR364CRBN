//======================================================
// peripheral setting routines
//======================================================

#include	"MC96FR364C.h"
#include	"func_def.h"

void BOD_init()
{
	// initialize BOD (Brown out detector)
	// BODR bit2~1 = BODout selection
	// - default is 00 (BODout1)
	BODR = 0x01;    	// setting
}

void ExINT_init()
{
	// initialize external interrupt
	EIPS5 = 0x05;   	// INT.5 = P05

	EIEDGE0 = 0x00; 	// INT.3~0 : level / edge
	EIEDGE1 = 0x0C; 	// INT.5~4 : level / edge
	EIPOLA = 0x20;  	// polarity
	EIFLAG = 0x00;  	// clear all flags
	IE |= 0x20;     	// INT. 5,4,3,2,1,0
	EIENAB = 0x20;  	// enable INT pin
}

void Timer0_init()
{
	// initialize Timer0
	// 8bit timer, period = 1.002667mS
	T0CR = 0x92;    	// timer setting
	T0DR = 0x2E;    	// period count
	T0CR |= 0x01;   	// clear counter
	IE1 |= 0x20;    	// Enable Timer0 interrupt
}

void WDT_clear()
{
	WDTMR |= 0x20;  	// Clear Watch-dog timer
}

void WDT_init()
{
	// initialize Watch-dog timer
	WDTR = 0xFF;    	// period
	WDTMR = 0xC0;   	// setting
	WDT_clear();
}

void clock_init()
{
	// 12MHz ring OSC.
	// Divided clock (12.000000MHz)
	SCCR = (SCCR & 0x9f) | 0x00;	// set clock divider
}

void port_init()
{
	// initialize ports
	//   2 : P23      out pFAN_LED1
	//   3 : P24      out pFAN_LED2
	//   5 : P30      out pPOWER_ON
	//   6 : P31      out pFAN_1
	//   7 : P32      out pFAN_2
	//   8 : P00      out pSCL
	//   9 : P01      out pFAN
	//  10 : P02      out POWER_LED
	//  11 : P03      out pLED_EN1
	//  12 : P04      out FAN_OFF
	//  13 : P05      in  SENSOR_IN
	//  14 : P06      out pTest1
	//  15 : P07      out pTest2
	//  16 : P10      in  Low_Bat
	//  17 : P11      in  FAN_KEY
	//  18 : P12      in  KEY
	//  19 : P13      in  VOICE_BUSY
	//  20 : P14      in  KEY_ADC
	//  21 : P15      out VOICE_CSB
	//  22 : P16      out VOICE_CLK
	//  23 : P17      out VOICE_SDI
	//  24 : P20      out 
	//  25 : P21      out 
	//  26 : P22      out 
	P0IO = 0xDF;    	// direction
	P0PU = 0x20;    	// pullup
	P0OD = 0x00;    	// open drain
	P0   = 0x00;    	// port initial value

	P1IO = 0xE0;    	// direction
	P1PU = 0x13;    	// pullup
	P1OD = 0x00;    	// open drain
	P1   = 0x00;    	// port initial value

	P2IO = 0xFF;    	// direction
	P2PU = 0x00;    	// pullup
	P2OD = 0x00;    	// open drain
	P2   = 0x00;    	// port initial value

	P3IO = 0xFF;    	// direction
	P3PU = 0x00;    	// pullup
	P3OD = 0x00;    	// open drain
	P3   = 0x00;    	// port initial value

	// Set port functions
	//PMISC0   = 0x??;	// USART port, REMOUT TR
	//PMISC1   = 0x??;	// Slew rate, IR pullup R
}

