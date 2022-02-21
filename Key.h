#ifndef _KEY_H_
#define _KEY_H_

extern uchr gcKey_cnt,gcKey_Data,gcKey_old_buff,gcKey_Buff,sensor_Buff,sensor_old_buff,Sensor_cnt,Sensor_Data;
extern bit  fgKey_flag,Sensor_flag,_Hot,_Power_Off;


extern void Key_Check_Rtn(void);
extern void Low_Batt(void);

#endif	// _KEY_H_
