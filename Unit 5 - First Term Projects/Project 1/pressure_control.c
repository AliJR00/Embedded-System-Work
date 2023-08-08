#include "pressure_control.h"


unsigned int value;
unsigned int threshold = 20;
unsigned int timer = 100000;

void pressure_S_set(int num)
{	
	value = num;

	(value>threshold)? (PC_state = control_on): (PC_state = control_off);

}




void control_on()
{
	Control_status = Control_working;
	int on = 1;
	int off = 0;
	alarm_set(on);
}

void control_off()
{
	Control_status = Control_idle;
	int off = 0;
	alarm_set(off);
}