#ifndef pressure_control_H_
#define pressure_control_H_

#include "driver.h"


void (*PC_state)();


enum{
	Control_idle,
	Control_working
}Control_status;

void pressure_S_set(int num);
void control_on();
void control_off();
extern void Delay(int nCount);
extern void alarm_set(int i);
extern void Set_Alarm_actuator(int i);


#endif