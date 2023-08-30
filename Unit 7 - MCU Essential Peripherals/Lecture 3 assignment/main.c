#include "GPIO/GPIO_Driver.h"






void gpioa_init()
{
	//PA1 floating input (by default)
	Pinconfig PA1;
	PA1.GPIO_PinNumber = GPIO_PinNum1;
	PA1.GPIO_PinMode = GPIO_INPUT_FLOATING;
	MCAL_GPIO_Init(GPIOA, &PA1);

	//PA13 floating input (by default)
	Pinconfig PA13;
	PA13.GPIO_PinNumber = GPIO_PinNum13;
	PA13.GPIO_PinMode = GPIO_INPUT_FLOATING;
	MCAL_GPIO_Init(GPIOA, &PA13);
}

void gpiob_init()
{
	Pinconfig PB1;
	PB1.GPIO_PinNumber = GPIO_PinNum1;
	//PB1 output mode at 10 mhz
	PB1.GPIO_PinSpeed = GPIO_SPEED_10M;
	//PB1 push pull output
	PB1.GPIO_PinMode = GPIO_OUTPUT_PUSHPULL;
	MCAL_GPIO_Init(GPIOB, &PB1);


	Pinconfig PB13;
	PB13.GPIO_PinNumber = GPIO_PinNum13;
	//PB13 output mode at 10 mhz
	PB13.GPIO_PinSpeed = GPIO_SPEED_10M;
	//PB13 push pull output
	PB13.GPIO_PinMode = GPIO_OUTPUT_PUSHPULL;
	MCAL_GPIO_Init(GPIOB, &PB13);
}

void clock_init()
{
	//enabling the clock on port A and B
	GPIOA_CLK_EN();
	GPIOB_CLK_EN();

}

void delay(int x)
{
	int i, j;

	for(i=0; i<x; i++)
	{
		for(j=0;j<2550;j++);
	}
}


int main()
{
	clock_init();
	gpioa_init();
	gpiob_init();

	while(1)
	{

	if(MCAL_GPIO_READPIN(GPIOA, GPIO_PinNum1) == GPIO_PIN_OFF)
	{
		MCAL_GPIO_TOGGLEPIN(GPIOB, GPIO_PinNum1);

		while(MCAL_GPIO_READPIN(GPIOA, GPIO_PinNum1) == GPIO_PIN_OFF);
	}

	if(MCAL_GPIO_READPIN(GPIOA, GPIO_PinNum13) == GPIO_PIN_ON)
	{
		MCAL_GPIO_TOGGLEPIN(GPIOB, GPIO_PinNum13);
	}

	delay(2000);

	}
}










