#include "US.h"
#include "DC.h"
#include "CA.h"





void setup()
{
	US_init();
	DC_init();
	DC_state = motor_stopping;
	US_state = USbusy;
	CA_state = CA_waiting;

}

int main()
{
	setup();

	while(1)
	{
	US_state();
	CA_state();
	DC_state();

	volatile int i;
	for(i=0; i<5000; i++);
	}
}
