//======================================================
//		file name: MC96FR116C.h
//		device   : MC96FR116C
//		version  : Ver1.0  
//		date     : 2014-08-12
//		compiler : Keil-C
//======================================================

#include	<intrins.h>

#ifndef _MC96FR364C_H_
#define _MC96FR364C_H_

sfr    P0        = 0x80;       // PORTCON      R/W 8'b0000_0000    P0 Data Register
	sbit	P07			= P0^7;
	sbit	P06			= P0^6;
	sbit	P05			= P0^5;
	sbit	P04			= P0^4;
	sbit	P03			= P0^3;
	sbit	P02			= P0^2;
	sbit	P01			= P0^1;
	sbit	P00			= P0^0;

sfr    P1        = 0x88;       // PORTCON      R/W 8'b0000_0000    P1 Data Register
	sbit	P17			= P1^7;
	sbit	P16			= P1^6;
	sbit	P15			= P1^5;
	sbit	P14			= P1^4;
	sbit	P13			= P1^3;
	sbit	P12			= P1^2;
	sbit	P11			= P1^1;
	sbit	P10			= P1^0;

sfr	P2			= 0x90;			// [R/W] Port 2 Data Reg.
	sbit	P27			= P2^7;
	sbit	P26			= P2^6;
	sbit	P25			= P2^5;
	sbit	P24			= P2^4;
	sbit	P23			= P2^3;
	sbit	P22			= P2^2;
	sbit	P21			= P2^1;
	sbit	P20			= P2^0;

sfr    P3        = 0xC0;       // PORTCON      R/W 8'b0000_0000    P3 Data Register
	sbit	P37			= P3^7;
	sbit	P36			= P3^6;
	sbit	P35			= P3^5;
	sbit	P34			= P3^4;
	sbit	P33			= P3^3;
	sbit	P32			= P3^2;
	sbit	P31			= P3^1;
	sbit	P30			= P3^0;


sfr    P0IO        = 0x98;       // PORTCON      R/W 8'b0000_0000    P0 Direction Register
sfr    P1IO        = 0xA0;       // PORTCON      R/W 8'b0000_0000    P1 Direction Register
sfr    P2IO        = 0xB0;       // PORTCON      R/W 8'b----_-000    P2 Direction Register
sfr    P3IO        = 0x9B;       // PORTCON      R/W 8'b0000_0000    P3 Direction Register

sfr    P0PC        = 0xC1;       // PORTCON      R/W 8'b0000_0000    P0 Pin Change Interrupt 

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// USART0                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    UCTRL01     = 0xE2;       // USART        R/W 8'b0000_0000    USART Control Register 1
sfr    UCTRL02     = 0xE3;       // USART        R/W 8'b0000_0000    USART Control Register 2
sfr    UCTRL03     = 0xE4;       // USART        R/W 8'b0000_0000    USART Control Register 3
sfr    USTAT0      = 0xE5;       // USART        R/W 8'b1000_0000    USART Status Register
sfr    UBAUD0      = 0xE6;       // USART        R/W 8'b1111_1111    USART BaudRate Low Register
sfr    UDATA0      = 0xE7;       // USART        R/W 8'b0000_0000    USART Data Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// USART1                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    UCTRL11     = 0xFA;       // USART        R/W 8'b0000_0000    USART Control Register 1
sfr    UCTRL12     = 0xFB;       // USART        R/W 8'b0000_0000    USART Control Register 2
sfr    UCTRL13     = 0xFC;       // USART        R/W 8'b0000_0000    USART Control Register 3
sfr    USTAT1      = 0xFD;       // USART        R/W 8'b1000_0000    USART Status Register
sfr    UBAUD1      = 0xFE;       // USART        R/W 8'b1111_1111    USART BaudRate Low Register
sfr    UDATA1      = 0xFF;       // USART        R/W 8'b0000_0000    USART Data Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// SYSCON:                                                       ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    BODR        = 0x86;       // BOD          R/W  8'b1000_0001    BOD Control Register
sfr    BODSR       = 0x8F;       // BOD          R/W  8'b0000_0000    BOD Control Status Register
sfr    PCON        = 0x87;       // PCON         W    8'b0000_0000    Stop and Sleep Mode Control Register
sfr    SCCR        = 0x8A;       // CLKGEN       R/W  8'b-000_--00    System Clock Control Register
sfr    BCCR        = 0x8B;       // BIT          R/W  8'b0111_0111    BIT Clock Control Register
sfr    BITR        = 0x8C;       // BIT          R    8'b0000_0000    Clock Control Register
sfr    CFGCR       = 0xF9;       // BIT          R    8'b0000_0001    Software Control Register
sfr    MCCR        = 0xEF;       // CLKGEN       R/W  8'b111-_-111    Main Oscillator Clock Control Register
sfr    NCCR        = 0x89;       // CLKGEN       R/W  8'b----_-111    Noise Clock Control Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// WDT                                                           ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    WDTR        = 0x8E;       // WDT          W    8'b1111_1111    Watch Dog Timer Register

sfr    WDTMR       = 0x8D;       // WDT          W    8'b000-_---0    Watch Dog Timer Mode Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// WT & IRCC                                                     ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    WTMR        = 0xD1;       // WT           R/W  8'b0000_0000    Watch Timer Mode Register
sfr    WTDR1       = 0xD4;       // WT           W    8'b--11_1111    Watch Timer Register
sfr    WTDR0       = 0xD5;       // WT           W    8'b1111_1111    Watch Timer Register
sfr    WTSR        = 0xD9;       // WT           R/W  8'b0000_0000    Watch Timer Status Register
sfr    WTHDR       = 0xDC;       // WT           R    8'b-000_0000    Watch Timer High Data Register
sfr    IRCC0       = 0xDD;       // WT           R/W  8'b0000_0000    IR Capture Control Register 0
sfr    IRCC1       = 0xDE;       // WT           R/W  8'b0000_0000    IR Capture Control Register 1
sfr    IRCC2       = 0xDF;       // WT           R/W  8'b0000_0000    IR Capture Control Register 2
sfr    IRCC3       = 0xDA;       // WT           R/W  8'b0000_0000    IR Capture Control Register 2
sfr    IRCC4       = 0xDB;       // WT           R/W  8'b0000_0000    IR Capture Control Register 2
sfr    WTCR0H      = 0xF1;       // WT           R/W  8'b--00_0000    Watch Timer Capture Register 0 High
sfr    WTCR0L      = 0xF2;       // WT           R/W  8'b0000_0000    Watch Timer Capture Register 0 High
sfr    WTCR1H      = 0xF3;       // WT           R/W  8'b--00_0000    Watch Timer Capture Register 0
sfr    WTCR1L      = 0xF4;       // WT           R/W  8'b0000_0000    Watch Timer Capture Register 0
sfr    WTCR2H      = 0xF5;       // WT           R/W  8'b--00_0000    Watch Timer Capture Register 0
sfr    WTCR2L      = 0xF6;       // WT           R/W  8'b0000_0000    Watch Timer Capture Register 0



//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// INTCON                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------ 0xA8
sfr     IE      = 0xA8; // [R/W] Interrupt Enable Register 0
sbit    EA      = IE^7;

sfr     IE1     = 0xA9; // [R/W] Interrupt Enable Register 1
sfr     IE2     = 0xAA; // [R/W] Interrupt Enable Register 2
sfr     IE3     = 0xAB; // [R/W] Interrupt Enable Register 3

sfr    IEN3        = 0xAB;       // INTCON       R/W  8'b0000_0000    Interrupt Enable Register High
sfr    IEN2        = 0xAA;       // INTCON       R/W  8'b0000_0000    Interrupt Enable Register High
sfr    IEN1        = 0xA9;       // INTCON       R/W  8'b0000_0000    Interrupt Enable Register Low
sfr    IEN0        = 0xA8;       // INTCON       R/W  8'b0000_0000    Interrupt Enable Register Low
sfr    EIFLAG      = 0xAC;       // PORTCON      R/W  8'b----_0000    External Interrupt Flag Register
sfr    EIEDGE0     = 0xAD;       // PORTCON      R/W  8'b----_0000    External Interrupt Edge Register
sfr    EIEDGE1     = 0xAE;       // PORTCON      R/W  8'b----_0000    External Interrupt Edge Register
sfr    EIPOLA      = 0xAF;       // PORTCON      R/W  8'b----_0000    External Interrupt Polarity Register
sfr    EIENAB      = 0xB1;       // PORTCON      R/W  8'b----_0000    External Interrupt Enable Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// TIMER0                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    T0CR        = 0xB2;       // TIMER0       R/W  8'b0000_0000    Timer 0 Mode Control Register 
sfr    T0          = 0xB3;       // TIMER0       R    8'b0000_0000    Timer 0 Register
sfr    T0DR        = 0xB3;       // TIMER0       W    8'b1111_1111    Timer 0 Data Register
sfr    CDR0        = 0xB3;       // TIMER0       R    8'b0000_0000    Timer 0 Capture Data Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// TIMER1                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    T1CR        = 0xB4;       // TIMER1       R/W  8'b0000_0000    Timer 1 Mode Control Register
sfr    T1DR        = 0xB5;       // TIMER1       W    8'b1111_1111    Timer 1 Data Register
sfr    PWM1PR      = 0xB5;       // TIMER1       W    8'b1111_1111    Timer 1 PWM Period Register
sfr    T1          = 0xB6;       // TIMER1       R    8'b0000_0000    Timer 1 Register
sfr    PWM1DR      = 0xB6;       // TIMER1       R/W  8'b0000_0000    Timer 1 PWM Duty Register
sfr    CDR1        = 0xB6;       // TIMER1       R    8'b0000_0000    Timer 1 Capture Data Register
sfr    PWM1HR      = 0xB7;       // TIMER1       W    8'b---0_0000    Timer 1 PWM High Register


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// TIMER2                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    T2CR        = 0xC6;       // TIMER2      R/W  8'b0000_0000    Timer 2 Mode Control Register
sfr    T2L         = 0xCF;       // TIMER2      R/W  8'b0000_0000    Timer 2 Data Low Register
sfr		T2DRL		= 0xCF;			// [W] Timer 2 Low Data Register
sfr		T2LDR		= 0xCF;			// [W] Timer 2 Low Data Register

sfr		CDR2L		= 0xCF;			// [R] Timer 2 Capture Data Low Register

sfr    T2H         = 0xC7;       // TIMER2      R/W  8'b0000_0000    Timer 2 Data High Register
sfr			T2DRH		= 0xC7;			// [W] Timer 2 High Data Register
sfr			T2HDR		= 0xC7;
sfr			CDR2H		= 0xC7;			// [R] Timer 2 Capture Data High Register

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// TIMER3                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    T3CR2       = 0xC9;       // TIMER3      R/W  8'b0000_0000    Timer 3 Mode Control Register 2
sfr    T3CR        = 0xCA;       // TIMER3      R/W  8'b0000_0000    Timer 3 Mode Control Register
sfr    T3L         = 0xCB;       // TIMER3      R/W  8'b0000_0000    Timer 3 Data Low Register
sfr    PWM3DRL     = 0xCB;       // TIMER3      R/W  8'b0000_0000    Timer 3 PWM Duty Low Register
sfr    CDR3L	    = 0xCB;       // TIMER3      R/W  8'b0000_0000    Timer 3 PWM Duty Low Register
sfr    T3H         = 0xCC;       // TIMER3      R/W  8'b0000_0000    Timer 3 Data High Register
sfr    PWM3DRH     = 0xCC;       // TIMER3      R/W  8'b0000_0000    Timer 3 PWM Duty High Register
sfr    CDR3H     = 0xCC;       // TIMER3      R/W  8'b0000_0000    Timer 3 PWM Duty High Register
sfr    T3DRL       = 0xCD;       // TIMER3      W    8'b1111_1111    Timer 3 Data Low Register
sfr    T3LDR       = 0xCD;       // TIMER3      W    8'b1111_1111    Timer 3 Data Low Register
sfr    PWM3PRL     = 0xCD;       // TIMER3      W    8'b1111_1111    Timer 3 PWM Period Low Register
sfr    T3DRH       = 0xCE;       // TIMER3      W    8'b1111_1111    Timer 3 Data High Register
sfr    T3HDR       = 0xCE;       // TIMER3      W    8'b1111_1111    Timer 3 Data High Register

sfr    PWM3PRH     = 0xCE;       // TIMER3      W    8'b1111_1111    Timer 3 PWM Period High Register


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// TIMER4                                                        ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// SPI                                                           ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// KEYSCAN                                                       ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    SMRR0       = 0xD2;       // KEYSCAN      R/W  8'b0000_0000     Standby Mode Release register #0
sfr    SMRR1       = 0xD3;       // KEYSCAN      R/W  8'b0000_0000     Standby Mode Release register #1
sfr    SRLC0       = 0xD6;       // KEYSCAN      R/W  8'b0000_0000     Standby Release Level Control register #0
sfr    SRLC1       = 0xD7;       // KEYSCAN      R/W  8'b0000_0000     Standby Release Level Control register #1
sfr    KITSR       = 0xF7;       // KEYSCAN      R/W  8'b0000_0000     Key Interrupt Trigger Select Register


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// REMOCON                                                       ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    RMR         = 0xE8;       // REMOCON      R/W  8'b0000_0000     REMOCON mode register
sfr    RDBH        = 0xC2;       // REMOCON      R/W  8'b1111_1111     REMOCON data high buffer
sfr    RDBL        = 0xC3;       // REMOCON      R/W  8'b1111_1111     REMOCON data low buffer
sfr    RDRH        = 0xC4;       // REMOCON      R/W  8'b1111_1111     REMOCON data high register
sfr    RDRL        = 0xC5;       // REMOCON      R/W  8'b1111_1111     REMOCON data low register
sfr    RDC1        = 0xBA;       // REMOCON      R    8'b0000_0000     REMOCON data counter
sfr    RDC0        = 0xBD;       // REMOCON      R    8'b0000_0000     REMOCON data counter
sfr    RODR        = 0xBE;       // REMOCON      R/W  8'b----_---0     REMOCON output data register
sfr    ROB         = 0xBF;       // REMOCON      R/W  8'b----_---0     REMOCON output buffer
sfr    CFHS        = 0xBB;       // REMOCON      R/W  8'b--11_1111     Carrier frequency high selection
sfr    CFLS        = 0xBC;       // REMOCON      R/W  8'b--11_1111     Carrier frequency low selection

//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// I2C                                                           ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

sfr    I2CCR       = 0x9C;       // I2C          R/W  8'b0000_0000     I2C Control Register
sfr    I2CSR       = 0x9D;       // I2C          R/W  8'b0000_0000     I2C Status Register
sfr    I2CSCLLR    = 0x9E;       // I2C          R/W  8'b0011_1111     I2C SCL Low Period Register
sfr    I2CSCLHR    = 0x9F;       // I2C          R/W  8'b0011_1111     I2C SCL High Period Register
sfr    I2CSDHR     = 0xA3;       // I2C          R/W  8'b0000_0001     I2C SDA Hold Register
sfr    I2CDR       = 0xA5;       // I2C          R/W  8'b0000_0000     I2C Data Register
sfr    I2CSAR      = 0xA6;       // I2C          R/W  8'b0000_0000     I2C Slave Address Register
sfr    I2CSAR1     = 0xA7;       // I2C          R/W  8'b0000_0000     I2C Slave Address Register1




//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// ADC                                                           ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// Flash and EEPROM Memory REGISTER                              ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////


sfr    MCRC_CTRL       = 0xA1;       // TEST_MODE    R/W  8'b0000_0000     Monitor CRC control
sfr    MCRC_DATA0      = 0x99;       // TEST_MODE    R/W  8'b0000_0000     Monitor CRC data 0
sfr    MCRC_DATA1      = 0x9A;       // TEST_MODE    R/W  8'b0000_0000     Monitor CRC data 1
	
sfr		FEMR     =  0xE1; // Flash and EEPROM mode register
sfr		FECR     =  0xEC; // Flash and EEPROM control register
sfr		FESR     =  0xED; // Flash and EEPROM status register
sfr		FETCR    =  0xEE; // Flash and EEPROM time control register
sfr		FEARL    =  0xEB; // Flash and EEPROM address register low
sfr		FEARM    =  0xEA; // Flash and EEPROM address register middle
sfr		FEARH    =  0xE9; // Flash and EEPROM address register high
//sfr	FSECR          =  0xEF      ;       // Flash and EEPROM data register


#define    UCTRL04     *(volatile unsigned char xdata *) 0x2F5A      // USART        R/W 8'b----_--00    USART Control Register 4

#define    RMR2       *(volatile unsigned char xdata *) 0x2F56;       // REMOCON      R/W 8'b----_---0      REMOCON mode 2 register
#define    P0PU        *(volatile unsigned char xdata *) 0x2F00      // PORTCON      R/W 8'b0000_0000    P0 Pull-up Register
#define    P1PU        *(volatile unsigned char xdata *) 0x2F01      // PORTCON      R/W 8'b0000_0000    P1 Pull-up Register
#define    P2PU        *(volatile unsigned char xdata *) 0x2F02      // PORTCON      R/W 8'b----_-000    P2 Pull-up Register
#define    P3PU        *(volatile unsigned char xdata *) 0x2F03      // PORTCON      R/W 8'b0011_1100    P3 Pull-up Register

#define    P0OD        *(volatile unsigned char xdata *) 0x2F08      // PORTCON      R/W 8'b0000_0000    P0 Open Drain Register
#define    P1OD        *(volatile unsigned char xdata *) 0x2F09      // PORTCON      R/W 8'b0000_0000    P1 Open Drain Register
#define    P2OD        *(volatile unsigned char xdata *) 0x2F0A      // PORTCON      R/W 8'b----_-000    P2 Open Drain Register
#define    P3OD        *(volatile unsigned char xdata *) 0x2F0B      // PORTCON      R/W 8'b0000_0000    P3 Open Drain Register




// PxBPC is spec. out
/*
#define    P0BPC       *(volatile unsigned char xdata *) 0x2F50      // PORTCON      R/W 8'b1111_1111    P0 BODOUT Pull-up Control Register

#define    P1BPC       *(volatile unsigned char xdata *) 0x2F51      // PORTCON      R/W 8'b1111_1111    P1 BODOUT Pull-up Control Register
#define    P2BPC       *(volatile unsigned char xdata *) 0x2F52      // PORTCON      R/W 8'b----_-111    P2 BODOUT Pull-up Control Register
#define    P3BPC       *(volatile unsigned char xdata *) 0x2F53      // PORTCON      R/W 8'b1111_1111    P3 BODOUT Pull-up Control Register
*/


#define    PMISC0      *(volatile unsigned char xdata *) 0x2F11      // PORTCON      R/W 8'b0000_0000    Port miscellaneous control register
#define    PMISC1      *(volatile unsigned char xdata *) 0x2F12      // PORTCON      R/W 8'b0000_0000    Port miscellaneous control register

#define    EIPS0       *(volatile unsigned char xdata *) 0x2F18      // PORTCON      R/W  8'b0000_0000    External Interrupt Port Selection 0 Register
#define    EIPS1       *(volatile unsigned char xdata *) 0x2F19      // PORTCON      R/W  8'b0000_0001    External Interrupt Port Selection 1 Register
#define    EIPS2       *(volatile unsigned char xdata *) 0x2F1A      // PORTCON      R/W  8'b0000_0010    External Interrupt Port Selection 2 Register
#define    EIPS3       *(volatile unsigned char xdata *) 0x2F1B      // PORTCON      R/W  8'b0000_0011    External Interrupt Port Selection 3 Register
#define    EIPS4       *(volatile unsigned char xdata *) 0x2F1C      // PORTCON      R/W  8'b0000_0100    External Interrupt Port Selection 4 Register
#define    EIPS5       *(volatile unsigned char xdata *) 0x2F1D      // PORTCON      R/W  8'b0000_0101    External Interrupt Port Selection 5 Register

#define    FETR          *(volatile unsigned char xdata *) 0x2F58    ;       // Flash and EEPROM test register
#define    FETR1         *(volatile unsigned char xdata *) 0x2F59    ;       // Flash and EEPROM test register
#define    CSUMH         *(volatile unsigned char xdata *) 0x2F06
#define    CSUMM         *(volatile unsigned char xdata *) 0x2F07
#define    CSUML         *(volatile unsigned char xdata *) 0x2F0F

#define    CRC_TADDR_E   *(volatile unsigned char xdata *) 0x2F28
#define    CRC_TADDR1    *(volatile unsigned char xdata *) 0x2F29
#define    CRC_TADDR0    *(volatile unsigned char xdata *) 0x2F2A
#define    CRC_CTRL      *(volatile unsigned char xdata *) 0x2F2B

// Flash secure control
#define    FSEC_LOCK_BADDR_E     *(volatile unsigned char xdata *) 0x2F60
#define    FSEC_LOCK_BADDR1      *(volatile unsigned char xdata *) 0x2F61
#define    FSEC_LOCK_BADDR0      *(volatile unsigned char xdata *) 0x2F62

#define    FSEC_LOCK_TADDR_E     *(volatile unsigned char xdata *) 0x2F63
#define    FSEC_LOCK_TADDR1      *(volatile unsigned char xdata *) 0x2F64
#define    FSEC_LOCK_TADDR0      *(volatile unsigned char xdata *) 0x2F65

#define    FSEC_UNLOCK_BADDR_E   *(volatile unsigned char xdata *) 0x2F66
#define    FSEC_UNLOCK_BADDR1    *(volatile unsigned char xdata *) 0x2F67
#define    FSEC_UNLOCK_BADDR0    *(volatile unsigned char xdata *) 0x2F68

#define    FSEC_UNLOCK_TADDR_E   *(volatile unsigned char xdata *) 0x2F69
#define    FSEC_UNLOCK_TADDR1    *(volatile unsigned char xdata *) 0x2F6A
#define    FSEC_UNLOCK_TADDR0    *(volatile unsigned char xdata *) 0x2F6B

#define    FSEC_CTRL             *(volatile unsigned char xdata *) 0x2F6C


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// The offset of reset and interrupt vector address              ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////
#define    OFFSET_INTV     *(volatile unsigned char xdata *) 0x2F6F


//////////////////////////////////////////////////////////////////////////
// ==================================================================== //
// TEST MODE REGISTER                                            ;       //
// ==================================================================== //
//////////////////////////////////////////////////////////////////////////

#define    TEST_REGA       *(volatile unsigned char xdata *) 0x2FE0      // TEST_MODE    W    8'b0000_0000     Function Test Reg. A
#define    TEST_REGB       *(volatile unsigned char xdata *) 0x2FE1      // TEST_MODE    W    8'b0000_0000     Function Test Reg. B
#define    TEST_REGC       *(volatile unsigned char xdata *) 0x2FE2      // TEST_MODE    W    8'b0000_0000     Function Test Reg. C
#define    TEST_REGD       *(volatile unsigned char xdata *) 0x2FE3      // TEST_MODE    W    8'b0000_0000     Function Test Reg. D

#define    FUSE_CONF       *(volatile unsigned char xdata *) 0x2FF0      // TEST_MODE    R/W  8'b0000_0000     FUSE Config setting
#define    FUSE_BGR        *(volatile unsigned char xdata *) 0x2FF1      // TEST_MODE    R/W  8'b0000_0000     FUSE BGR trimming
#define    FUSE_BODR       *(volatile unsigned char xdata *) 0x2FF2      // TEST_MODE    R/W  8'b0000_0000     FUSE BODR trimming
#define    FUSE_BODI0      *(volatile unsigned char xdata *) 0x2FF3      // TEST_MODE    R/W  8'b0000_0000     FUSE BODI0 trimming
#define    FUSE_BODI       *(volatile unsigned char xdata *) 0x2FF4      // TEST_MODE    R/W  8'b0000_0000     FUSE BODI trimming
#define    FUSE_FLSS       *(volatile unsigned char xdata *) 0x2FF5      // TEST_MODE    R/W  8'b0000_0000     FUSE FLASH sense amp trimming
#define    FUSE_FLSV       *(volatile unsigned char xdata *) 0x2FF6      // TEST_MODE    R/W  8'b0000_0000     FUSE FLASH VPP trimming
#define    FUSE_IRCBM      *(volatile unsigned char xdata *) 0x2FF7      // TEST_MODE    R/W  8'b----_0000     FUSE IRC BMR trimming
#define    FUSE_IRCT       *(volatile unsigned char xdata *) 0x2FF8      // TEST_MODE    R/W  8'-----_-000     FUSE IRC temp. trimming
#define    FUSE_IRCIF_8_6  *(volatile unsigned char xdata *) 0x2FF9      // TEST_MODE    R/W  8'b----_-000     FUSE IRC center freq. trimming
#define    FUSE_IRCIF_5_0  *(volatile unsigned char xdata *) 0x2FFA      // TEST_MODE    R/W  8'---00_0000     FUSE IRC inside freq. trimming

#define    FUSE_USER_TRIM  *(volatile unsigned char xdata *) 0x2FFF      //              R/W  8'b0000_0000     FUSE user trim


#define    MOPT_DIDL       *(volatile unsigned char xdata *) 0x2F85      // TEST_MODE    R/W  8'b0000_0000     metal_option DIDL
#define    MOPT_DIDH       *(volatile unsigned char xdata *) 0x2F86      // TEST_MODE    R/W  8'b0000_0000     metal_option DIDH

#define    TEST_ERP0       *(volatile unsigned char xdata *) 0x2F90
#define    TEST_ERP1       *(volatile unsigned char xdata *) 0x2F91
#define    TEST_ERP2       *(volatile unsigned char xdata *) 0x2F92
#define    TEST_ERP3       *(volatile unsigned char xdata *) 0x2F93

#define    TEST_PC0        *(volatile unsigned char xdata *) 0x2FC0
#define    TEST_PC1        *(volatile unsigned char xdata *) 0x2FC1

#define    XBANK           *(volatile unsigned char xdata *) 0x2F0E      // XBANK        R/W  8'b0000_0000     XBANK register


#endif		//_MC96FR364_H_

#define		cli()		do{IE &= ~0x80;}while(0)
#define		sei()		do{IE |=  0x80;}while(0)
#define		NOP			_nop_()
