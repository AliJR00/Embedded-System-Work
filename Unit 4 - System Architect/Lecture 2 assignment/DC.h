
#ifndef DC_H_
#define DC_H_

#include <stdio.h>
#include <stdlib.h>

extern void DC_motor(int speed);
enum{
	motor_idling,
	motor_moving
}DCMOTOR_status;

void (*DC_state)();

void DC_init();
void DC_motor(int s);
void motor_driving();
void motor_stopping();


#endif
