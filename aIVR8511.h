

#ifndef _ALVR511_H_
#define _ALVR511_H_


//extern 
extern uchr Voice_Addr;
//extern 
extern uchr Voice_Rtn_Step;
//extern 
extern uchr Voice_Cmd_Step,Voice_Command,_Level_Set,Voice_Addr_Back;


extern void Voice_Mode_Rtn(void) ;

extern void Mode_Proc_Rtn(void);
//extern void Voice_F_Rtn(unsigned char a);
void play_a_voice(unsigned char a);
void reset_voice_ic(void);
void delay_us(unsigned int a);
void send_a_spi_word(uint a);
//void ddddddd_rn(void);



#endif			
