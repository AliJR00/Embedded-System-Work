#define F_CPU 1000000UL
#include <util/delay.h>


#define DDRD *((volatile unsigned int*) 0x31)
#define PIND *((volatile unsigned int*) 0x30)
#define PORTD *((volatile unsigned int*) 0x32)	

#define DDRC *((volatile unsigned int*) 0x34)
#define PORTC *((volatile unsigned int*) 0x35)




void gpiod_init()
{
	//PD 4 output
	DDRD |= 1<<4;
	
	//PD 5 output
	DDRD |= 1<<5;
	
	//PD 6 output
	DDRD |= 1<<6;
	
	//PD 7 output
	DDRD |= 1<<7;
	
	//PD0 input
	DDRD &= ~(1<<0);
	
	//PD1 input
	DDRD &= ~(1<<1);
	
	//PD2 input
	DDRD &= ~(1<<2);
	
	
	
	//configuring 7segment output pins
	DDRC |= 0b111111<<2;
		
}






int main()
{
	gpiod_init();
	 volatile unsigned int count = 0, flag = 0;
	
	while(1)
	{
		
	//buzzer
	if(((PIND)&(1<<0)) == 1)
	{
		PORTD |= 1<<4;
		
		_delay_ms(5000);
		PORTD &= ~(1<<4);
	}
	
	// led toggling
	if(((PIND & (1<<1))>>1) == 0)
	{
		flag =0;
	}
	
	if(((PIND & (1<<1))>>1) == 1)
	{
		
		
		if(flag == 0)
		{
			
		if(count == 3)
		{
			count = -1;
			PORTD &= ~(0b111<<5);
		}
		
		switch(count)
		{
			case 0:
			PORTD |= 1<<5;
			_delay_ms(500);
			break;
			
			case 1:
			PORTD |= 1<<6;
			_delay_ms(500);
			break;
			
			case 2:
			PORTD |= 1<<7;
			_delay_ms(500);
			break;
			
		}
		count ++;
		flag++;
		}
	}
	
	
	//7segment
	
	if(((PIND & (1<<2))>>2) == 1)
	{
		int i, j, ff=0;
		for(i=0; i<10; i++)
		{
			for(j=0; j<10; j++)
			{
				PORTC = 0b1000 | (j<<4);
				_delay_ms(1000);
				PORTC = 0b0100 | (i<<4);
				_delay_ms(1000);
				
				if(((PIND & (1<<1))>>1) == 1 || ((PIND & (1<<0))) == 1)
				{
					ff=1;
					break;
				}

			}
			if(ff==1)
			{
				break;
			}
		}
	}
	



	}
	
}