#include "FIFO.h"


FIFO_STAT FIFO_INIT(FIFO_BUF* FIFO, type* buffer, uint32_t length)
{

	FIFO->base = buffer;
	FIFO->head = FIFO->base;
	FIFO->tail = FIFO->base;

	FIFO->length = length;
	FIFO->count = 0;


	FIFO->verify = FIFO->base + 1;

	if(!FIFO->head || !FIFO->base)
		return FIFO_ERROR;

	return FIFO_NO_ERROR;
}

FIFO_STAT FIFO_ISFULL(FIFO_BUF* FIFO)
{
	if(FIFO->base + 1 != FIFO->verify)
			return FIFO_ERROR;

	if(FIFO->count == FIFO->length)
		return FIFO_FULL;

	return FIFO_NO_ERROR;
}

FIFO_STAT enqueue(FIFO_BUF* FIFO, type item)
{
	if(FIFO->base + 1 != FIFO->verify)
	{
		printf("The Queue doesn't exist\n");
		return FIFO_ERROR;
	}
	if(FIFO_ISFULL(FIFO) == FIFO_FULL)
	{
		printf("the Queue is full!\n");
		return FIFO_FULL;
	}

	*(FIFO->head) = item;
	if(FIFO->head == (FIFO->base + FIFO->length*sizeof(type)))
		FIFO->head = FIFO->base;
	else
		FIFO->head++;


	FIFO->count++;
	printf("%x is added to the Queue.\n", item);

	return FIFO_NO_ERROR;
}

FIFO_STAT dequeue(FIFO_BUF* FIFO)
{
	if(FIFO->base + 1 != FIFO->verify)
		{
			printf("The Queue doesn't exist\n");
			return FIFO_ERROR;
		}
	if(FIFO->count == 0)
	{
		printf("The Queue is empty!\n");
		return FIFO_EMPTY;
	}

	type item = *(FIFO->tail);

	if(FIFO->tail == (FIFO->base + FIFO->length*sizeof(type)))
		FIFO->tail = FIFO->base;
	else
		FIFO->tail++;


	FIFO->count--;
	printf("%x is removed from the Queue.\n", item);
	return item;

}

FIFO_STAT PRINT(FIFO_BUF* FIFO)
{
	if(FIFO->base + 1 != FIFO->verify)
			{
				printf("The Queue doesn't exist\n");
				return FIFO_ERROR;
			}
		if(FIFO->count == 0)
		{
			printf("The Queue is empty!\n");
			return FIFO_EMPTY;
		}

	unsigned int i;
	type* temp = FIFO->tail;
	printf("The Queue has %d elements:\n", FIFO->count);
	for(i=0; i<FIFO->count; i++)
	{
		printf("%x\n", *temp);
		temp++;
	}
	return FIFO_NO_ERROR;


}


