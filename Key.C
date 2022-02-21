
#include	"Global.h"	                    

uchr Rx_Buff1[32];


uchr gcKey_cnt,gcKey_Data,gcKey_old_buff,gcKey_Buff,sensor_Buff,sensor_old_buff,Sensor_cnt,Sensor_Data;
bit  fgKey_flag,Sensor_flag,_Power_Off;

#define Key_Power  1
#define Key_Fan  2
#define Low_Bat_Cnt_Ini  2




void Key_Check_Rtn(void)
{
  
	gcKey_Buff=0;
	if(Key_Reg>1000)gcKey_Buff=1;
	if(!pKey_Fan)gcKey_Buff|=2;	
	if(gcKey_Buff==gcKey_old_buff)
	{
  		if(gcKey_cnt==100&&_First_Key==0&&gcKey_Buff==1)//power
  		{
	  		Key_Bit=1;
	  		if(Mode==70)return;
  			if(gcKey_Buff=gcKey_Buff)
  			{
  				Mode=100;
  			}
  		}		
  		if(gcKey_cnt==100&&Sec_Fuction_Time&&gcKey_Buff==3)// toggle
  		{
//  			int i;
	  		 if(Voice_Stop==0)
	  		 {
	  		 	Voice_Stop=1;	Sec_Fuction_Time1=100;//10초간 소리허용
	  		 	Mode=59;//무음모드
	  		 	S_Step=0;
	  		 }		
	  		 else 
	  		 {
	  		 	Voice_Stop=0;
	  		 	Mode=58;//음성모드
	  		 	S_Step=0;
			}
	  		 Rx_Buff1[0]=Voice_Stop;
			//i=CodeFlash_Erase(509,1);	//400 => 0x6400~6db6	2487 byte
			//if(i==0)
			{
				//i=CodeFlash_Write(Rx_Buff1,509,1);
				HAL_FlashPageWrite(8,1,0);
				Voice_Stop=coderom[0];
			}			  		 	
  		}		
  		
  		
  		if(++gcKey_cnt>5)	//
		{
			if(!gcKey_Buff)
			{
				fgKey_flag=1;
				gcKey_cnt=0;
				_First_Key=0;
			}
			else if(fgKey_flag)
			{
				fgKey_flag=0;
				gcKey_Data=gcKey_Buff;
				//gcKey_Buff=0;
			}
		}
	}
	else
	{
		gcKey_cnt=0;
		gcKey_old_buff=gcKey_Buff;
		gcKey_Buff=0;
	}
	
	if(gcKey_Data&&!gcKey_Buff)
	{
		if(Key_Bit){gcKey_Data=0;return;}
		if(gcKey_Data==1)//Power
		{
			//if(++Mode>2)Mode=1;	
			//S_Step=0;
		}	
		
		if(gcKey_Data==2)//fan key
		{
			if(Mode==2)
			{
				if(++Fan_Mode>2)
				{
					Fan_Mode=0;
				}	
				Fan_Frag=Fan_Mode;
				S_StepF=0;
			}
		}
		gcKey_Data=0;
	}		
}	

void Low_Batt(void)
{
	if(Mode==70)return;
	if(!pLow_Batt)Low_Bat_Cnt++;
	else Low_Bat_Cnt=0;
	if(Low_Bat_Cnt==Low_Bat_Cnt_Ini)//50mS
	{
		Key_Bit=1;
		Mode_Step=0;
		Mode=70; 
	}
	
	
}



 