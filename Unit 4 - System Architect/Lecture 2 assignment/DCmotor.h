#ifndef DC_H_
#define DC_H_

#include "state.h"

enum DC{
	DC_idle,
	DC_busy
}DC_state_id;

void DC_init();
STATE_define(DC_Idle);
STATE_define(DC_Busy);

extern void (*DC_state)();


#endif 
