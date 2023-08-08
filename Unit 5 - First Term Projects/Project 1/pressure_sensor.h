	


#ifndef pressure_sensor_H_
#define pressure_sensor_H_


#include "driver.h"

void (*PS_state)();

enum{
	Psensor_BUSY
}Psensor_status;

extern void pressure_S_set(int num);
void Psenosr_busy();
void pressureS_init();
extern int getPressureVal();

#endif
