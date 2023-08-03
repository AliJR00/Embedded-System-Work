#include "DCmotor.h"
#include "state.h"



unsigned int DC_speed;

void (*DC_state)();

void DC_init()
{
	printf("DC_init \n");
}

void DC_motor (int s)
{
	DC_speed =s ;
	DC_state = STATE(DC_Busy);
	printf("CA->->->speed=%d-> DC\n",DC_speed);

}

STATE_define(DC_Idle)
{
	DC_state_id = DC_idle;
	DC_state = STATE(DC_Idle);
	printf("DC_idle state : speed=%d \n \n \n",DC_speed);
}

STATE_define(DC_Busy)
{	
	DC_state_id = DC_busy;

	DC_state = STATE(DC_busy);
	printf("DC_busy state : speed=%d \n \n \n",DC_speed);
}


