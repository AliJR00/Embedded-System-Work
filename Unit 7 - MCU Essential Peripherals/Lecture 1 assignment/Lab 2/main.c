
#define DDRD *(volatile unsigned int*) (0x31)
#define PORTD *(volatile unsigned int*) (0x32)


void gpiod_init()
{
	DDRD |= 0b1111<<4;
}

void delay(int x)
{
	unsigned int i, j;
	
	for(i=0; i<x; i++)
	{
		for(j=0; j<255000; j++);
	}
	
}

void main()
{
	while(1)
	{
		PORTD |= 1<<5;
		delay(1);
		PORTD &= ~(1<<5);
		delay(.5);
		
		PORTD |= 1<<6;
		delay(1);
		PORTD &= ~(1<<6);
		delay(.5);
		
		PORTD |= 1<<7;
		delay(1);
		PORTD &= ~(1<<7);
		delay(.5);
		
		PORTD |= 1<<4;
		delay(1);
		PORTD &= ~(1<<4);
		delay(.5);
		
	}
	
}
