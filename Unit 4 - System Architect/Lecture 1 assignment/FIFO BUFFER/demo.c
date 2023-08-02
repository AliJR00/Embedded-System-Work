
#include <stdlib.h>
#include "FIFO.h"


void  main()
{
	type* arr = (type*) malloc(5*sizeof(type));

	FIFO_BUF fifo, fifooooooo;

	FIFO_INIT(&fifo, arr, 5);

	for(int i=0; i<8; i++)
	{
		 enqueue(&fifo, i);
	}

	for(int i=0; i<3; i++)
		{
			 dequeue(&fifo);
		}

	PRINT(&fifo);

	for(int i=0; i<3; i++)
			{
				 dequeue(&fifo);
			}

	PRINT(&fifooooooo);
	dequeue(&fifooooooo);
	enqueue(&fifooooooo,5);



}
