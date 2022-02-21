#ifndef _REG_H_
#define _REG_H_

 
//-----------------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////////////
//---------- Function Return  Massage ----------//
#define Output			1
#define Input			0
#define High			1
#define Low				0
#define ON				1
#define OFF				0
#define ERR_OK			1	
#define ERR_NOISE		0
#define _On				0
#define _Off 			1

/////////////////////////////////////////////////////////////
extern SFR Flag0;//	@0xC0;
//#define  _Key_Flag				Flag0.BIT.b0	 // 
#define  fgProc_1ms				Flag0.BIT.b1	 // 
#define  fgProc_10ms			Flag0.BIT.b2	 // 
#define  fgProc_300ms			Flag0.BIT.b3	 // 
#define  fgProc_500ms			Flag0.BIT.b4
#define  fgAd_Complete			Flag0.BIT.b5	 //
#define  fgProc_100ms			Flag0.BIT.b6	 // 


extern TYPE1	User3_Bit_Reg;
#define	User3_Reg					User3_Bit_Reg.Ram_Car	
#define	_First_Key							User3_Bit_Reg.Ram_Bit.b0
#define	Key_Bit							User3_Bit_Reg.Ram_Bit.b1
#define	_Wink							User3_Bit_Reg.Ram_Bit.b2
#define	_Wink_1							User3_Bit_Reg.Ram_Bit.b3
#define	_D4							User3_Bit_Reg.Ram_Bit.b4
#define	_D5							User3_Bit_Reg.Ram_Bit.b5
#define	_D6							User3_Bit_Reg.Ram_Bit.b6
#define	_D7							User3_Bit_Reg.Ram_Bit.b7


#define	Led1_Reg						Led1_Bit_Reg.Ram_Car	
#define	_Led_Hot_Lock2					Led1_Bit_Reg.Ram_Bit.b0
#define	_Led_Hot_Lock1					Led1_Bit_Reg.Ram_Bit.b1
#define	_Led_Hot1						Led1_Bit_Reg.Ram_Bit.b2
#define	_Led_Hot2						Led1_Bit_Reg.Ram_Bit.b3
#define	_Led_Normal2					Led1_Bit_Reg.Ram_Bit.b4
#define	_Led_Normal1					Led1_Bit_Reg.Ram_Bit.b5
#define	_Led_Start_Stop1				Led1_Bit_Reg.Ram_Bit.b6
#define	_Led_Start_Stop2				Led1_Bit_Reg.Ram_Bit.b7

#define	Led2_Reg						Led2_Bit_Reg.Ram_Car	
#define	_Led_Cold1						Led2_Bit_Reg.Ram_Bit.b0
#define	_Led_Cold2						Led2_Bit_Reg.Ram_Bit.b1
#define	_Led_Leak						Led2_Bit_Reg.Ram_Bit.b3
#define	_Led_No_Water					Led2_Bit_Reg.Ram_Bit.b4
#define	_Led_Power						Led2_Bit_Reg.Ram_Bit.b5
 
#define	Led3_Reg						Led3_Bit_Reg.Ram_Car	
#define	_Led_Heat_On					Led3_Bit_Reg.Ram_Bit.b1
#define	_Led_Heat_Off					Led3_Bit_Reg.Ram_Bit.b0

#define	Led4_Reg						Led4_Bit_Reg.Ram_Car	
#define	_Led_Cold_On					Led4_Bit_Reg.Ram_Bit.b1
#define	_Led_Cold_Off					Led4_Bit_Reg.Ram_Bit.b0

extern uchr Mode,Mode_Step,Fan_Mode,Ad_Cnt,Off_Cnt,Wink_Reg,S_Time,Buzzer_Cnt,S_Step,S_StepF,End_Step,Wink_1_Reg;
extern uint Key_Reg,Touch_On,sys_Total_Time_Cnt,sys_Wait_Time,_Wait,Sys_Time_Cnt,Sys_Err,Low_Bat_Cnt,pSensor_In_cnt,S_Cnt,Step_Sys_Time_Cnt,Voice_Time,A_Time,Select;
extern uchr Fan_Frag,aaa;
extern uchr S_Cnt_Interval,S_Cnt_Interval_2,Sens_F,Voice_cnt,Mode_Interval,Sec_Fuction_Time,Voice_Stop,Sec_Fuction_Time1,Start_Time,Sensor_time;
extern uint imsi_Int; 

#endif	// _REG_H_