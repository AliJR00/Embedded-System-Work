
#include "LIFO.h"
#include <stdlib.h>


void  main()
{
	type* arr = (type*) malloc(5*sizeof(type));

	LIFO_BUF lifo, LIFO;

	LIFO_INIT(&lifo, arr, 5);

	for(int i=0; i<8; i++)
	{
		 PUSH(&lifo, i);
	}

	for(int i=0; i<3; i++)
		{
			 POP(&lifo);
		}

	PRINT(&lifo);

	for(int i=0; i<3; i++)
			{
				 POP(&lifo);
			}

	PRINT(&LIFO);
	POP(&LIFO);
	PUSH(&LIFO,5);



}
