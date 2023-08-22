

#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile unsigned int*) (RCC_BASE + 0x18)

#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00

#define GPIOA_CRL *(volatile unsigned int*) (GPIOA_BASE + 0x00)
#define GPIOB_CRL *(volatile unsigned int*) (GPIOB_BASE + 0x00)
#define GPIOA_CRH *(volatile unsigned int*) (GPIOA_BASE + 0x04)
#define GPIOB_CRH *(volatile unsigned int*) (GPIOB_BASE + 0x04)

#define GPIOA_IDR *(volatile unsigned int*) (GPIOA_BASE + 0x08)
#define GPIOB_ODR *(volatile unsigned int*) (GPIOB_BASE + 0x0C)



void gpioa_init()
{
	//PA1 floating input (by default)
	GPIOA_CRL |= 1<<6;
	GPIOA_CRL &= ~(1<<7);

	//PA13 floating input (by default)
	GPIOA_CRH |= 1<<22;
	GPIOA_CRH &= ~(1<<23);
}

void gpiob_init()
{
	//PB1 output mode at 10 mhz
	GPIOB_CRL |= 1<<4;
	//PB1 push pull output
	GPIOB_CRL &= ~(0b11<<6);

	//PB1 output mode at 10 mhz
	GPIOB_CRH |= 1<<20;
	//PB1 push pull output
	GPIOB_CRH &= ~(0b11<<22);
}

void clock_init()
{
	//enabling the clock on port A and B
	RCC_APB2ENR |= 0b11<<2;

}

void delay(int x)
{
	int i, j;

	for(i=0; i<x; i++)
	{
		for(j=0;j<255;j++);
	}
}


void main()
{
	clock_init();
	gpioa_init();
	gpiob_init();





	while(1)
	{
	if(((GPIOA_IDR & (1<<1)) >> 1) == 0)
	{
		GPIOB_ODR ^= 1<<1;

		while(((GPIOA_IDR & (1<<1)) >> 1) == 0);
	}

	if(((GPIOA_IDR & (1<<13)) >> 13) == 1)
	{
		GPIOB_ODR ^= 1<<13;
	}

	delay(2);

	}
}








