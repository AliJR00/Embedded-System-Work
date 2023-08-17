
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR *(volatile unsigned int*) (RCC_BASE + 0x18)
#define GPIOA_CRH *(volatile unsigned int*) (GPIOA_BASE +0x04)
#define GPIOA_ODR *(volatile unsigned int*) (GPIOA_BASE + 0x0C)



int main(void)
{
    RCC_APB2ENR |= 1<<2;
    GPIOA_CRH &= 0x0fffff;
    GPIOA_CRH |= 0x200000;

    while(1)
    {
    	GPIOA_ODR |= 1UL<<3;
    	for(int i=0; i<6005; i++);
    	GPIOA_ODR &= ~(1UL<<3);
    	for(int i=0; i<6005; i++);
    }


}
