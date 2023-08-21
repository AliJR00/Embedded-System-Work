#include <avr/interrupt.h>
#include <util/delay.h>

#define SREG_R *(volatile unsigned char*) (0x5F)

#define GICR_R *(volatile unsigned char*) (0x5B)
#define MCUCR_R *(volatile unsigned char*) (0x55)
#define MCUCSR_R *(volatile unsigned char*) (0x54)
#define GIFR_R *(volatile unsigned char*) (0x5A)

#define DDRD_R *(volatile unsigned char*) (0x31)
#define PORTD_R *(volatile unsigned char*) (0x32)






void interrupt_init()
{
	//rising edge trigger for INT1
	MCUCR_R |= 0b11<<2;
	//any logical change trigger for INT0
	MCUCR_R |= 0b01<<0;
	//falling edge trigger for INT2
	MCUCSR_R &= ~(1<<6);
	//enabling the external interrupt pin for INT0/1/2
	GICR_R |= 0b111<<5;
	//enabling global interrupt
	SREG_R |= 1<<7;
}

void gpio_init()
{
	//configure the direction of pins 5 6 7 as output
	DDRD_R |= 0b111<<5;
}

void main()
{
	interrupt_init();
	gpio_init();
	while(1);
}

ISR(INT0_vect)
{
	//TURN ON LED 0
	PORTD_R |= 1<<5;
	_delay_ms(1000);
	PORTD_R &= ~(1<<5);

	GIFR_R |= 1<<6;

}
ISR(INT1_vect)
{
	//TURN ON LED 0
	PORTD_R |= 1<<6;
	_delay_ms(1000);
	PORTD_R &= ~(1<<6);

	GIFR_R |= 1<<7;
}
ISR(INT2_vect)
{
	//TURN ON LED 0
	PORTD_R |= 1<<7;
	_delay_ms(1000);
	PORTD_R &= ~(1<<7);

	GIFR_R |= 1<<5;
}
