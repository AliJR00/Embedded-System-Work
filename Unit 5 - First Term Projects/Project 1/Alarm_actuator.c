#include "Alarm_actuator.h"




void alarm_init()
{
	AA_state = alarm_idling;
}


void alarm_set(int i)
{
	(i==1)? (AA_state = alarm_working): (AA_state = alarm_idling);
}

void alarm_working()
{
	Alarm_status = Alarm_working;
	
	Set_Alarm_actuator(0);
	Delay(600000);
	Set_Alarm_actuator(1);
	Delay(600000);

}


void alarm_idling()
{
	Alarm_status = Alarm_idle;
	
	Set_Alarm_actuator(1);


}