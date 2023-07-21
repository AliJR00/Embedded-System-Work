#include "platformtypes.h"

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR *(vuint32_t*) (RCC_BASE + 0x18)
#define GPIOA_CRH *(vuint32_t*) (GPIOA_BASE + 0x04)
#define GPIOA_ODR (vuint32_t*) (GPIOA_BASE + 0x0C)

typedef union
{
	vuint32_t all;
	struct{
		vuint32_t reserved:13;
		vuint32_t P13:1;
	}Pin;
}ODR;

volatile ODR* ODRpins = (volatile ODR*) GPIOA_ODR;


int main(void)
{
    RCC_APB2ENR |= 1<<2;
    GPIOA_CRH &= 0x0fffff;
    GPIOA_CRH |= 0x200000;

    while(1)
    {
    	ODRpins->Pin.P13 = 1;
    	for(int i=0; i<6005; i++);
    	ODRpins->Pin.P13 = 0;
    	for(int i=0; i<6005; i++);
    }


}
