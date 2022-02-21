//======================================================
// interrupt routines
//======================================================

#include	"Global.h"
uchr r10mS_Cnt,r100mS_Cnt,r50mS_Cnt,r1S_Cnt;
bit _1mS,_10mS,_100mS,_50mS,_1S;


void INT_Ext5() interrupt 5
{
	// External interrupt 5
	// TODO: add your code here
}

void INT_Timer0() interrupt 11
{
		_1mS=1;
	if(++r10mS_Cnt>=10)
	{
		r10mS_Cnt=0;//Step_Sys_Time_Cnt++;
		_10mS=1;	
		if(++r50mS_Cnt>=5)
		{
			r50mS_Cnt=0;
			_50mS=1;
		}		
		if(++r100mS_Cnt>=10)
		{
			Sys_Err++;
			if(++Wink_1_Reg>5)
			{
				Wink_1_Reg=0;
				_Wink_1=~_Wink_1;
			}
			if(++Wink_Reg>2)
			{
					Wink_Reg=0;
				_Wink=~_Wink;
			}
			r100mS_Cnt=0;
			_100mS=1;
		}		

		if(++r1S_Cnt>100)
		{
			r1S_Cnt=0;_1S=1;
		}		
	}	
}

