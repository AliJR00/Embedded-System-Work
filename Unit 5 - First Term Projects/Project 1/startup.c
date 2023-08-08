extern unsigned int E_data;
extern unsigned int E_text;
extern unsigned int E_bss;
extern unsigned int S_data;
extern unsigned int S_bss;
extern unsigned int stack_top;



void reset_handler();
extern int main();

void defualt_handler()
{
	reset_handler();
}

void NMI_handler() __attribute__((weak, alias("defualt_handler")));;
void hardfualt_handler() __attribute__((weak, alias("defualt_handler")));;
void memmanage_handler() __attribute__((weak, alias("defualt_handler")));;
void busfault_handler() __attribute__((weak, alias("defualt_handler")));;
void usagefaullt_handler() __attribute__((weak, alias("defualt_handler")));;

unsigned int vectors[] __attribute__((section(".vectors"))) =
{
	(unsigned int) &stack_top,
	(unsigned int) &reset_handler,
	(unsigned int) &NMI_handler,
	(unsigned int) &hardfualt_handler,
	(unsigned int) &memmanage_handler,
	(unsigned int) &busfault_handler,
	(unsigned int) &usagefaullt_handler
};


void reset_handler()
{
	unsigned int data_size = (unsigned char*) &E_data - (unsigned char*) &S_data;
	unsigned char* data_src = (unsigned char*) &E_text;
	unsigned char* data_des = (unsigned char*) &S_data;

	int i;
	for(i=0; i<data_size; i++)
	{
		*((unsigned char*) data_des++) = *((unsigned char*) data_src++);
	}

	unsigned int bss_size = (unsigned char*) &E_bss - (unsigned char*) &S_bss;
	unsigned char* bss_des = (unsigned char*) &S_bss;


	for(i=0; i<bss_size; i++)
	{
		*((unsigned char*) bss_des++) = (unsigned char) 0;
	}

	main();
}


