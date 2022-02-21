#include	"Global.h"


uchr Interval_Time,Sensor1_Reg1,Sensor1_cnt,Sensor1_Reg,Sensor1_Reg_Old;
 
bit _Key,_Ion_Touch;
#define Interval_Time_Ini 1


void Mode_Proc(void)//100ms
{
	////////////////////////////////////////////////////////////////////////////////////
	//time over
	if(Mode==50)
	{
		pFAN_1=0;pFAN_2=1;Fan_Mode=0;
		pFan_Led_1=0;pFan_Led_2=0;
		pPower_Led=0;pLed_En=0;pFan_En=0;pFan_Off=0;
		Buzzer_Cnt=0;Sens_F=0;Key_Bit=1;
		//play_a_voice(16);
		if(Voice_Stop)//무음일때
		{
			play_a_voice(18);
		}
		else if(!Voice_Stop)//무음 아닐때 
		{
			play_a_voice(16);
		}	
		Mode++;Off_Cnt=0;
		S_Cnt=0;S_Cnt_Interval=0;Mode_Interval=0;
	}
	else if(Mode==51&&++Off_Cnt>=40)//20)
	{
		pPower_On=0;
		while(1);
	}	
	
	//////////////////////////////////////////////////////////////////////////////////
	//lowbatt
	if(Mode==70)
	{
		if(Mode_Step==0) 
		{
			pFAN_1=0;pFAN_2=1;Fan_Mode=0;
			pFan_Led_1=0;pFan_Led_2=0;
			pPower_Led=0;pLed_En=0;pFan_En=0;pFan_Off=0;
			Buzzer_Cnt=0;Sens_F=0;Key_Bit=1;
			//play_a_voice(5);
			if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(5);
			}	
			Mode_Step++;Off_Cnt=0;
			S_Cnt=0;S_Cnt_Interval=0;Mode_Interval=0;
			Wink_Reg=0;r100mS_Cnt=0;
		}
		else if(Mode_Step==1)
		{
			if(_Wink)//wink 동작 시 중간 리셋 부분에 led 동작 이상 
			{
				pFan_Led_1=1;
				pFan_Led_2=1;
				pPower_Led=1;
			}
			else
			{
				pFan_Led_1=0;
				pFan_Led_2=0;
				pPower_Led=0;
				if(++Off_Cnt>=15)
				{
					pPower_On=0;
					while(1);
				}
			}
			
		}
	}
	///////////////////////////////////////////////////////
	//모자 미착용 종료
	if(Mode==80)
	{
		pFAN_1=0;pFAN_2=1;Fan_Mode=0;
		pFan_Led_1=0;pFan_Led_2=0;
		pPower_Led=0;pLed_En=0;pFan_En=0;pFan_Off=0;
		Buzzer_Cnt=0;Sens_F=0;Key_Bit=1;
		//play_a_voice(16);
		Mode++;Off_Cnt=0;
		S_Cnt=0;S_Cnt_Interval=0;Mode_Interval=0;
	}
	else if(Mode==81&&++Off_Cnt>=40)//25)
	{
		pPower_On=0;
		while(1);
	}	
	///////////////////////////////////////////////////////////////////////////////////
	//end 
	if(Mode==100)
	{
		pFAN_1=0;pFAN_2=1;Fan_Mode=0;
		pFan_Led_1=0;pFan_Led_2=0;
		pPower_Led=0;pLed_En=0;pFan_En=0;pFan_Off=0;
		Buzzer_Cnt=0;Sens_F=0;Key_Bit=1;
		//play_a_voice(3);
		if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
				Mode=102;
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(3);
				Mode++;Off_Cnt=0;
				S_Cnt=0;S_Cnt_Interval=0;Mode_Interval=0;
			}	
		//Mode++;Off_Cnt=0;
		//S_Cnt=0;S_Cnt_Interval=0;Mode_Interval=0;
	}
	else if(Mode==101&&++Off_Cnt>=30)//15)
	{
		pPower_On=0;
		while(1);
	}
	else if(Mode==102&&++Off_Cnt>=10)//15)
	{
		pPower_On=0;
		while(1);
	}
	
	
	
}





