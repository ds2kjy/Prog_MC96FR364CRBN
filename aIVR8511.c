 #include	"Global.h"
#include <stdio.h>

#define tack_wav  1
#define tack_wav1 2
#define Ext_Mode  3
#define Ext_Mode_Wave 4


uchr Voice_Addr,Voice_Rtn_Step;
uchr Voice_Cmd_Step,Voice_Command,_Level_Set,Voice_Addr_Back;

//void Voice_F_Rtn(uchr a)
//{
//		  Voice_Addr=a;
//	Voice_Addr=tack_wav1 	;			
//	
//	Voice_Rtn_Step=0;	
//	pVoice_Clk=1;
//	pVoice_Data=0;
//	pVoice_Cs=1;
//}	

void Voice_Mode_Rtn(void)
{	
	if(!pBusy&&Voice_Rtn_Step==0&&!Voice_Addr)
	{
		if(Voice_Rtn_Step==0)
		{
			pVoice_Clk=1;
			pVoice_Data=0;
			pVoice_Cs=1;
		}
	}	
}
/****************************************************************************
  1. output a 10 bit command serially to the voice pcb.
     spec for 10 command as follows
        command      bit9  8  7  6  5  4  3  2  1  0
     ------------    ----  -  -  -  -  -  -  -  -  -
     Stop_command :     0  1  x  x  x  x  x  x  x  x     (x= don't care)
     Play_command :     1  0 d7 d6 d5 d4 d3 d2 d1 d0     (d7-1 = address)
     Volume control :   1  1  0  0  0  0  0 d2 d1 d0     (d2-0: 001=v_level 1, 010="2, 011="3, 100="4)
  2. set LEDs = voice address
*/


//---------------------------------------------------------------------------
// send 16 bits SPI command serially from bit15 to bit0.

void delay_us(unsigned int a)
{
		pPower_On^=1;
		while(a--);
 }
 



void send_a_spi_word(uint a)
{   int i = 0;

  //  MCU_BUSY_PIN = H;                 //turn_on MCU_BUSY_LED

    pVoice_Cs = 1;                       //stand-by status,
    delay_us(500);
    pVoice_Clk = 0;                      //stand-by status,
    delay_us(500);
    pVoice_Cs = 0;
    while(i < 16)
    {   pVoice_Clk = 0;
        delay_us(500);
        if(a&0x8000)      pVoice_Data = 1;
        else pVoice_Data = 0;
        a *= 2;                 //shift left
        delay_us(500);
        pVoice_Clk = 1;
         delay_us(500);
        i++;
    }
    pVoice_Clk = 0;                      //added by Jimmy            22/05/2015
    delay_us(500);
    pVoice_Data = 0;                      //for test only
    delay_us(500);
    pVoice_Cs = 1;                       //stand-by status
    //MCU_BUSY_PIN = L;                 //turn_off MCU_BUSY_LED
}


/****************************************************************************
                           Reset the Voice IC
 ***************************************************************************/
void reset_voice_ic(void)
{
        pVoice_Reset = 1;                  //reset the voice IC
        pVoice_Reset = 0;
        
}


void play_a_voice(uchr a)
{
    uint Command;
    if(Voice_Stop==1&&Sec_Fuction_Time1==0)
    {
    	if(a!=18&&a!=10&&a!=6)
    	return;
    }		
    
    Command=0x9800 +a;
                       //play command
    send_a_spi_word(Command);
    delay_us(500);                      //min. delay time before busy_high = ~1/Fs
}




	
//void ddddddd_rn(void)
//{
//	Voice_F_Rtn(1);
//	Voice_Mode_Rtn();
//	reset_voice_ic();
//	play_a_voice(1);
//}	