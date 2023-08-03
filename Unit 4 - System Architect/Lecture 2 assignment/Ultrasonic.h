#ifndef US_H_
#define US_H_


#include "state.h"

enum US{
	US_busy
}US_state_id;

void US_init();
STATE_define(US_Busy);

extern void (*US_state)();


#endif
