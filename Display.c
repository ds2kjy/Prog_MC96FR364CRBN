#include	"Global.h"	                    



void S_Step_Up_Rtn(void)
{
	S_Step++;
	Step_Sys_Time_Cnt=0;
}


void Proc_Rtn(void)//0.1S
{
	Step_Sys_Time_Cnt++;
	if(Mode==70)return;
	if(Fan_Mode==0)
	{
		//Fan_Frag=0;//////////////////////////활성화하면 mode1로넘어갈때 팬꺼짐
		if(S_StepF==0)
		{
			Key_Bit=1;
			//play_a_voice(13);
			pFan_En=0;
			pFan_Off=0;
			pFAN_1=0;
			pFAN_2=1;
			pFan_Led_1=0;
			pFan_Led_2=0;
			if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(13);//PASS
			}	
			S_StepF++;Step_Sys_Time_Cnt=0;
		}
		else if(S_StepF==1&&Step_Sys_Time_Cnt>=3)
		{
			pFan_En=0;
			pFan_Off=0;
			pFAN_1=0;
			pFAN_2=1;
			pFan_Led_1=0;
			pFan_Led_2=0;
			Key_Bit=0;
		}		
	}
	else if(Fan_Mode==1)
	{
	//	Fan_Frag=1;
		if(S_StepF==0)
		{
			Key_Bit=1;
			//play_a_voice(1);
			if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(1);//PASS
			}	
			S_StepF++;Step_Sys_Time_Cnt=0;
		}
		else if(S_StepF==1&&Step_Sys_Time_Cnt>=3)
		{
			pFan_En=1;
			pFan_Off=1;
			pFAN_1=1;
			pFAN_2=1;
			pFan_Led_1=1;
			pFan_Led_2=0;
			Key_Bit=0;
		}					
	}
	else if(Fan_Mode==2)
	{
		//Fan_Frag=2;
		if(S_StepF==0)
		{	
			Key_Bit=1;
			//play_a_voice(2);
			if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(2);//PASS
			}	
			S_StepF++;Step_Sys_Time_Cnt=0;
		}	
		else if(S_StepF==1&&Step_Sys_Time_Cnt>=3)
		{
			Key_Bit=0;
			pFan_En=0;
			pFan_Off=1;
			pFAN_1=0;
			pFAN_2=0;
			pFan_Led_1=1;
			pFan_Led_2=1;
		}	
		
	}
	else Step_Sys_Time_Cnt=0;
		
			
	if(Mode==58)	//음성모드
	{
		if(S_Step==0)
		{
			//play_a_voice(6);
			S_Step_Up_Rtn();
		}
		else if(S_Step==1)//&&Step_Sys_Time_Cnt>=10)
		{
			play_a_voice(11);//PASS
			S_Step_Up_Rtn();
		}
		else if(S_Step==2&&Step_Sys_Time_Cnt>=10)
		{
			Mode=1;S_Step=0;
		}		
	}	
	else if(Mode==59)	//무음모드
	{
		if(S_Step==0)
		{
			//play_a_voice(6);
			S_Step_Up_Rtn();
		}
		else if(S_Step==1)
		{
			play_a_voice(10);//PASS
			S_Step_Up_Rtn();
		}
		else if(S_Step==2&&Step_Sys_Time_Cnt>=10)
		{
			Mode=1;S_Step=0;
		}		
	}	
	else if(Mode==60)	//START
	{
		if(S_Step==0)
		{
			play_a_voice(6);//PASS
			S_Step_Up_Rtn();
		}
		else if(S_Step==1&&Step_Sys_Time_Cnt>=15)
		{
			//play_a_voice(0);
			if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
				S_Step=3;
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(0);
				S_Step_Up_Rtn();
			}	
			//S_Step_Up_Rtn();
	   }	
		else if(S_Step==2&&Step_Sys_Time_Cnt>=45)//70)
		{
			Wink_1_Reg=0;
			Mode=1;
		}	
		else if(S_Step==3&&Step_Sys_Time_Cnt>=30)
		{
			Wink_1_Reg=0;
			Mode=1;
		}	
		
	}
	else if(Mode==1)	
	{
		//Start_Time++;
		if(++Start_Time>=20)
		{
			if(_Wink_1)
			{
				pPower_Led=1;
			}
			else
			{
				pPower_Led=0;
			}
		}
		//Wink_1_Reg=0;
		//pFan_En=0;  
		//pFan_Off=0; 
		//pFAN_1=0;   
		//pFAN_2=1; 
		pLed_En=0;
		if(++Voice_Time>60)
		{
			Voice_cnt++;	
			if(Voice_cnt<3)
			{
				//play_a_voice(4);
				if(Voice_Stop)//무음일때
				{
					play_a_voice(18);
				}
				else if(!Voice_Stop)//무음 아닐때 
				{
					play_a_voice(4);
				}	
				Voice_Time=0;
			}
		}		
	}
	
	else if(Mode==2)	
	{
		Voice_Time=0;
		
		pPower_Led=1;
		if(S_Step==0)
		{
			Key_Bit=1;
			//pLed_En=1;
			//play_a_voice(8);
			if(Voice_Stop)//무음일때
			{
				play_a_voice(18);
			}
			else if(!Voice_Stop)//무음 아닐때 
			{
				play_a_voice(8);
			}	
			S_Step_Up_Rtn(); 
			//Fan_Frag=1;
		}
		else if(S_Step==1&&Step_Sys_Time_Cnt>=15)
		{
			Key_Bit=0;
			pLed_En=1;
		   pPower_Led=1;
		  // S_Step_Up_Rtn(); 
		  } 
		// else if(S_Step==2&&Step_Sys_Time_Cnt>=10)
		// {
		// 	if(Fan_Frag==1)
		//	{
		//  		Fan_Mode=1;
		//  		pFan_En=1;  
		//		pFan_Off=1; 
		//		pFAN_1=1;   
		//		pFAN_2=1;   
		//  	}
		//  	else if(Fan_Frag==2)
		//  	{
		//  		Fan_Mode=2;
		//  		pFan_En=0;  
		//		pFan_Off=1; 
		//		pFAN_1=0;   
		//		pFAN_2=0;   		   		
		//  	}		
		//  	else if(Fan_Frag==0)
		//  	{
		//  		Fan_Mode=0;
		//  		pFan_En=0;  
		//		pFan_Off=0; 
		//		pFAN_1=0;   
		//		pFAN_2=1;   		   		
		//  	}	
		// }
		
	}		
}
