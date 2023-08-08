#ifndef Alarm_actuator_H_
#define Alarm_actuator_H_


#include "driver.h"

void (*AA_state)();

enum{
	Alarm_idle,
	Alarm_working
}Alarm_status;



extern void Set_Alarm_actuator(int i);
extern void Delay(int nCount);
void alarm_init();
void alarm_set(int i);
void alarm_working();
void alarm_idling();












#endif