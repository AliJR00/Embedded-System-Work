#include "DC.h"

int speed;

void DC_init()
{
	printf("DC motor is initialized\n");
}

void DC_motor(int s)
{
	speed = s;
	(s!=0) ? (DC_state = motor_driving) : (DC_state = motor_stopping);
	printf("CA-------> DC\n");
}

void motor_driving()
{
	DCMOTOR_status = motor_moving;
	printf("The speed of motor is %d\n\n", speed);


}



void motor_stopping()
{
	DCMOTOR_status = motor_idling;

	printf("the motor stopped!\n\n");

}

