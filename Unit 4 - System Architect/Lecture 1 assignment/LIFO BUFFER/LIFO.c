#include "LIFO.h"


LIFO_STAT LIFO_INIT(LIFO_BUF* LIFO, type* buffer, uint32_t length)
{

	LIFO->base = buffer;
	LIFO->head = LIFO->base;
	LIFO->length = length;
	LIFO->count = 0;


	LIFO->verify = LIFO->base + 1;

	if(!LIFO->head || !LIFO->base)
		return LIFO_ERROR;

	return LIFO_NO_ERROR;
}

LIFO_STAT LIFO_ISFULL(LIFO_BUF* LIFO)
{
	if(LIFO->base + 1 != LIFO->verify)
			return LIFO_ERROR;

	if(LIFO->count == LIFO->length)
		return LIFO_FULL;

	return LIFO_NO_ERROR;
}

LIFO_STAT PUSH(LIFO_BUF* LIFO, type item)
{
	if(LIFO->base + 1 != LIFO->verify)
	{
		printf("The stack doesn't exist\n");
		return LIFO_ERROR;
	}
	if(LIFO_ISFULL(LIFO) == LIFO_FULL)
	{
		printf("the stack is full!\n");
		return LIFO_FULL;
	}

	*(LIFO->head) = item;
	LIFO->head++;
	LIFO->count++;
	printf("%x is added to the stack.\n", item);

	return LIFO_NO_ERROR;
}

LIFO_STAT POP(LIFO_BUF* LIFO)
{
	if(LIFO->base + 1 != LIFO->verify)
		{
			printf("The stack doesn't exist\n");
			return LIFO_ERROR;
		}
	if(LIFO->count == 0)
	{
		printf("The stack is empty!\n");
		return LIFO_EMPTY;
	}

	LIFO->head--;
	type item = *(LIFO->head);
	LIFO->count--;
	printf("%x is removed from the stack.\n", item);
	return item;

}

LIFO_STAT PRINT(LIFO_BUF* LIFO)
{
	if(LIFO->base + 1 != LIFO->verify)
			{
				printf("The stack doesn't exist\n");
				return LIFO_ERROR;
			}
		if(LIFO->count == 0)
		{
			printf("The stack is empty!\n");
			return LIFO_EMPTY;
		}

	unsigned int i;
	type* temp = LIFO->head - 1;
	printf("The stack has %d elements:\n", LIFO->count);
	for(i=0; i<LIFO->count; i++)
	{
		printf("%x\n", *temp);
		temp--;
	}
	return LIFO_NO_ERROR;


}


