#ifndef _DISPLAY_H_
#define _DISPLAY_H_

//extern  void Display_Rtn(void);
extern void Temp_Set_Rtn(uint ttt);
extern void Time_Set_Rtn(uint ttt);

#define Led_Full_Spec   40
#define Led_Half_Spec   5
//extern void Display_Rtn(void);
extern void LD1217_Set_Rtn(uchr CH,uchr VALUE,uchr Ed);
extern void Fnd_Data_Re_Rtn1(uchr data1,uchr ch);
extern void Fnd_Data_Re_Rtn2(uchr data1,uchr ch);
extern void Initial_Display(uchr a);
extern void LD1217_Display_Set_Rtn_1(void);
extern void LD1217_Display_Set_Rtn_2(void);
extern void MC2102_Key_Scan(void);
extern void S_Step_Up_Rtn(void);
extern void Proc_Rtn(void);
//void Display_Rtn_T(void);

extern TYPE1	Led1_Bit_Reg;
extern TYPE1	Led2_Bit_Reg;
extern TYPE1	Led3_Bit_Reg;
extern TYPE1	Led4_Bit_Reg; 

extern uchr LD1217_1_Reg_00;
extern uchr LD1217_1_Reg_01;
extern uchr LD1217_1_Reg_02;
extern uchr LD1217_1_Reg_03;
extern uchr LD1217_1_Reg_04;
extern uchr LD1217_1_Reg_05;
extern uchr LD1217_1_Reg_06;
extern uchr LD1217_1_Reg_07;
extern uchr LD1217_1_Reg_08;
extern uchr LD1217_1_Reg_09;
extern uchr LD1217_1_Reg_0A;
extern uchr LD1217_1_Reg_0B;
extern uchr LD1217_1_Reg_0C;
extern uchr LD1217_1_Reg_0D;




#endif	// _DISPLAY_H_
