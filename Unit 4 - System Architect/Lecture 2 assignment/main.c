/*
 * main.c
 *
 *  Created on: Jul 29, 2023
 *      Author: Ahmed & Wessam
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	/* init all the drivers */
	/* IRQ */
	/* init HAL US driver DC driver */
	/* init BLOCK */
	US_init();
	DC_init();
	/* Set States pointers for each block */
	CA_state = STATE(CA_Waiting);
	US_state = STATE(US_Busy);
	DC_state = STATE(DC_Idle);


}

int main()
{
	volatile int d;
	setup();
	while (1)
	{
		/* call state for each block */
		CA_state();
		US_state();
		DC_state();
		/* delay */
		for(d=0; d<= 10000000; d++);
	}
	return 0;

}


