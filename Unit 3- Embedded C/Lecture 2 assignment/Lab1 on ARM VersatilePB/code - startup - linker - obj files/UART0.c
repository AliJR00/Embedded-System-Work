
#include "UART0.h"

#define UART0 *((volatile unsigned int*) ((unsigned int*) 0x101f1000))

void UART_send(unsigned char *stringinput)
{
	while(*stringinput != 0)
	{
	UART0 = (unsigned int) *stringinput;
	stringinput++;
	}
}
