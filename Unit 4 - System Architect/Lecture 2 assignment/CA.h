

#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>

extern void DC_motor(int s);
void (*CA_state)();
void US_distance_set(int distance);
void  CA_waiting();
void  CA_driving();
extern void DC_motor(int s);


#endif
