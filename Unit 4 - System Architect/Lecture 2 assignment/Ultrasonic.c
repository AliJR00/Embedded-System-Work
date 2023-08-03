
#include "Ultrasonic.h"

extern void (*US_state)();

unsigned int distance;


int generate_random(int l,int r,int count)
{
	int i,rand_num=0;
	for(i=0; i<count; i++)
	{
		rand_num = (rand() % (r-l+1)) +l;
		return rand_num;
	}
}

void US_init ()
{
	printf("UC_init\n");
}
STATE_define(US_Busy)
{
	US_state_id = US_busy;
	
	distance = generate_random(45,55,1);
	
	printf("US_busy state : distance : %d \n",distance);

	US_distance_set(distance);
	US_state = STATE(US_Busy);
}
