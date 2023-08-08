#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "pressure_sensor.h"
#include "Alarm_actuator.h"
#include "pressure_control.h"


void setup()
{
	pressureS_init();
	alarm_init();
	GPIO_INITIALIZATION();

}

void main (){



	setup();
	
	while (1)
	{	
		 PS_state();
		 PC_state();
		 AA_state();
	}

}
