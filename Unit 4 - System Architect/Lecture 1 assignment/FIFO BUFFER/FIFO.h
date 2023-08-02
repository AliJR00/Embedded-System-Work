

#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>
#include <stdio.h>

#define type uint32_t

typedef struct
{
	unsigned int count;
	unsigned int length;
	type* base;
	type* head;
	type* tail;

	type* verify;
}FIFO_BUF;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_ERROR,
	FIFO_EMPTY,
	FIFO_FULL
}FIFO_STAT;


FIFO_STAT FIFO_INIT(FIFO_BUF* FIFO, type* buffer, uint32_t length);
FIFO_STAT enqueue(FIFO_BUF* FIFO, type item);
FIFO_STAT dequeue(FIFO_BUF* FIFO);
FIFO_STAT PRINT(FIFO_BUF* FIFO);
FIFO_STAT FIFO_ISFULL(FIFO_BUF* FIFO);

#endif



