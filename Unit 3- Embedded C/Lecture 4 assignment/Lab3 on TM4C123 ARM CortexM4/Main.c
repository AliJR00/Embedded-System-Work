#define CYCTL_RCGC2_R *((volatile unsigned long*)(0x400fe000 + 0x108))
#define GPIOF_DATA *((volatile unsigned long*) (0x40025000 + 0x3fc))
#define GPIOF_DIR *((volatile unsigned long*) (0x40025000 + 0x400))
#define GPIOF_DEN *((volatile unsigned long*) (0x40025000 + 0x51c))

void main(void)
{
	CYCTL_RCGC2_R = 0x20;
	volatile unsigned long loop;
	for(loop=0; loop<500; loop++);

	GPIOF_DIR |= 1<<3;
	GPIOF_DEN |= 1<<3;
	

	while(1)
		{
			GPIOF_DATA |= 1<<3;
			for(loop=0; loop<5000; loop++);
			GPIOF_DATA &= ~(1<<3);
			for(loop=0; loop<5000; loop++);

		}

}