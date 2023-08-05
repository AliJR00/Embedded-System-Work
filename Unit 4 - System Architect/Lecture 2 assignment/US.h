
#ifndef US_H_
#define US_H_

#include <stdio.h>
#include <stdlib.h>

extern void US_distance_set(int distance);

enum {
	US_busy
}US_status;

void (*US_state)();
void USbusy();
void US_init();

#endif
