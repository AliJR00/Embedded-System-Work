

#ifndef LIFO_H_
#define LIFO_H_

#include <stdint.h>
#include <stdio.h>

#define type uint32_t

typedef struct
{
	unsigned int count;
	unsigned int length;
	type* base;
	type* head;
	type* verify;
}LIFO_BUF;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_ERROR,
	LIFO_EMPTY,
	LIFO_FULL
}LIFO_STAT;


LIFO_STAT LIFO_INIT(LIFO_BUF* LIFO, type* buffer, uint32_t length);
LIFO_STAT PUSH(LIFO_BUF* LIFO, type item);
LIFO_STAT POP(LIFO_BUF* LIFO);
LIFO_STAT PRINT(LIFO_BUF* LIFO);
LIFO_STAT LIFO_ISFULL(LIFO_BUF* LIFO);

#endif



