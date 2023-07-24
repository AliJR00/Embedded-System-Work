#include "UART0.h"


unsigned char stringtext[100] = "Learn in depth <Ali>";

void main()
{
	UART_send(stringtext);
}