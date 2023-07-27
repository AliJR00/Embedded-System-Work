#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define APB2ENR *((volatile uint32_t*)(RCC_BASE + 0x18))
#define GPIOA_CRH *((volatile uint32_t*) (GPIOA_BASE + 0x04))	
#define GPIOA_ODR (volatile uint32_t*)(GPIOA_BASE + 0x0c)

typedef union
{
	volatile uint32_t all_pins;
	struct{
		volatile uint32_t reserved: 13;
		volatile uint32_t P_13:1;
	}Pin;
}ODR;


volatile ODR* ODR_R = (volatile ODR*) GPIOA_ODR; 

void main()
{
	APB2ENR = 1<<2;
	GPIOA_CRH &= 0x0fffff;
	GPIOA_CRH |= 0x200000;

	while(1)
	{
	int i;
	ODR_R-> Pin.P_13 = 1;
	for(i=0; i<7000; i++);

	ODR_R-> Pin.P_13 = 0;
	for(i=0; i<7000; i++);
		}
}