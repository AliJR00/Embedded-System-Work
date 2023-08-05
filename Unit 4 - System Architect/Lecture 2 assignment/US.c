#include "US.h"


int generate_random(int i, int f, int s)
{
	for(int j=0; j<s; j++)
	{
		int randnum = (rand() % (f-i+1)) + i;
		return randnum;
	}

}



void US_init()
{
	printf("Ultrasonic is initialized\n");
}

void USbusy()
{
	US_status = US_busy;

	int distance = generate_random(45,55,1);

	printf("Ultrasonic distance = %d \n", distance);
	US_distance_set(distance);
	US_state = USbusy;

}


