//======================================================
// Main program routine
// - Device name  : MC96FR364C
// - Package type : 28TSSOP
//======================================================
// For XDATA variable : V1.041.00 ~
#define		MAIN	1

// Generated    : Tue, Feb 15, 2022 (16:35:46)
 #include	"Global.h"

//#define Wait_Time_ON_Ini	180// 대기 시간
#define Time_ON_Ini	600// 동작 시간
void Dly_Rtn(uint a)
{
	while(a--);	
}	
unsigned int     Command;
extern uchr Rx_Buff1[32];


void Ini_Set_Rtn(void)
{
	// TODO: add your main code here
	Mode=60;S_Step=1;play_a_voice(6);
	SCL=0;_First_Key=1;Key_Bit=0;
	sys_Total_Time_Cnt=0;Low_Bat_Cnt=0;Off_Cnt=0;sys_Wait_Time=0;S_Time=0;S_Cnt=0;Wink_1_Reg=0;
	Fan_Mode=0;Mode_Step=0;/////////////////////////////////////////
	pFAN_1=0;
	pFAN_2=1;
	pFan_Led_1=0;pFan_Led_2=0;
	pPower_Led=1;//초기 이니셜 시 파워led켬
	pLed_En=0;pFan_En=0;Sens_F=0;pFan_Off=0;
	S_Cnt_Interval=0;S_Cnt_Interval_2=0;Mode_Interval=0;
	Step_Sys_Time_Cnt=0;Voice_Time=0;A_Time=0;
	pVoice_Reset=0;
	Voice_Addr=1;
	reset_voice_ic();
	Command=0xA800 ;
 	send_a_spi_word(Command);
   //play_a_voice(6);
   S_StepF=1;End_Step=0;Start_Time=0;aaa=1;	
}	

void main()
{
	cli();          	// disable INT. during peripheral setting
	port_init();    	// initialize ports
	clock_init();   	// initialize operation clock
	BOD_init();     	// initialize BOD (Brown out detector)
	ExINT_init();   	// initialize external interrupt
	Timer0_init();  	// initialize Timer0
	WDT_init();     	// initialize Watch-dog timer
	sei();          	// enable INT.
	
	// TODO: add your main code here
	Ini_Set_Rtn();
	Rx_Buff1[0]=1;Rx_Buff1[1]=2;Rx_Buff1[2]=3;Rx_Buff1[3]=4;
	Sec_Fuction_Time=30;//3초이내
	Sec_Fuction_Time1=0;
	Voice_Stop=coderom[0];//1이면 무음
	//if(Voice_Stop==1)Mode=1;//무음이면 바로 진입
  	while(1)
	{
		if(_1mS)
		{
			_1mS=0;
			pPower_On^=1;
		}	
		
		if(_10mS)
		{
			_10mS=0;
			if(Sec_Fuction_Time1)Sec_Fuction_Time1--;
			Key_Check_Rtn();
			Voice_Mode_Rtn();///////////////////////////////////////////
			Low_Batt();
			//Ad_Cont_Rtn();
		}	
		if(_50mS)
		{
			_50mS=0;	
		}		
		
		if(_100mS)
		{
			_100mS=0;
			if(Sec_Fuction_Time)Sec_Fuction_Time--;
			Select=1;
			SCL=1;
			//Dly_Rtn(250);
			Dly_Rtn(1000);////
			SCL=0;
			Select=0;
			Mode_Proc();
			Proc_Rtn();
			if(Mode<50)
			{
			if(Voice_cnt>2)
			{
				if(End_Step==0)
				{
					//play_a_voice(16);
					if(Voice_Stop)//무음일때
					{
						play_a_voice(18);
					}
					else if(!Voice_Stop)//무음 아닐때 
					{
						play_a_voice(16);	
					}	
					Key_Bit=1;
					Mode=80;
				}
			}
				if(++S_Cnt_Interval>=10)//초기화 시간
				{	
					S_Cnt_Interval=0;
					if(S_Cnt>=3)
					{	
						S_Cnt=100;
						if(Mode!=2)
						{
							Mode=2;
							Voice_cnt=0;
							S_Step=0;
						}
					}	
					else if(S_Cnt<3)
					{
						if(Mode==2)
						{
							if(++A_Time>1)
							{
								A_Time=0;
								if(S_Cnt<3)
								{
									Mode=1;
									if(sys_Total_Time_Cnt>=2)
									{                        
										Voice_Time=57;         
									} 
									//if(Fan_Mode==1)
									//{
									//	Fan_Frag=1;
									//}
									//else if(Fan_Mode==2)	
									//{
									//	Fan_Frag=2;
									//}
									//else if(Fan_Mode==0)	
									//{
									//	Fan_Frag=0;
									//}	
									//if(sys_Total_Time_Cnt>=2)
									//{
									//	Voice_Time=50;
									//}	                       
								}
							}		
						}	
					}
				S_Cnt=0;		
				}
			}
		}
		
		if(_1S)
		{
			_1S=0;
			//Proc_Rtn();
			sys_Wait_Time++;
			if(Mode==2)//10분
			{
				sys_Wait_Time=0;
				sys_Total_Time_Cnt++;
				if(sys_Total_Time_Cnt==540)
				{	
					//play_a_voice(12);//비프음후 5분남았습니다.					
					if(Voice_Stop)//무음일때
					{
						play_a_voice(18);
					}
					else if(!Voice_Stop)//무음 아닐때 
					{
						play_a_voice(12);//PASS
					}	
				}	
				else if(sys_Total_Time_Cnt==Time_ON_Ini)
				{ 
					Key_Bit=1;
					Mode=50; 
				}	
			}
		}	
	}
}
