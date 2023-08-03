#ifndef CA_H_
#define CA_H_

#include "state.h"

enum CA{
	CA_waiting,
	CA_driving
}CA_state_id;

STATE_define(CA_Waiting);
STATE_define(CA_Driving);


extern void (*CA_state)();



#endif
