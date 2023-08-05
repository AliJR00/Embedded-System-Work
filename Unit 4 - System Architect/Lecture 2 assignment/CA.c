#include "CA.h"


unsigned int CA_distance;
int CA_threshold = 50 ;
int CA_speed;

void US_distance_set(int distance)
{
	CA_distance = distance;

	printf("US----->CA\n");

	(CA_distance>= CA_threshold)? (CA_state = CA_waiting): (CA_state = CA_driving);

}

void  CA_waiting()
{
	printf("There are obstacles!\n");

	CA_speed = 0;
	DC_motor(CA_speed);

}

void  CA_driving()
{
	printf("No obstacles!\n");

	CA_speed = 30;
	DC_motor(CA_speed);

}
