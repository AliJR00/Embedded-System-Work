
#include "pressure_sensor.h"




void pressureS_init()
{
	PS_state = Psenosr_busy;
}





void Psenosr_busy()
{
	int value;

	value = getPressureVal();

	pressure_S_set(value);

	Psensor_status = Psensor_BUSY;

}