extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;


void reset_handler();
extern void main(void);


void default_handler()
{
	reset_handler();
}

void NMI_handler() __attribute__((weak, alias("default_handler")));;
void hard_fault_handler() __attribute__((weak, alias("default_handler")));;
void memory_managment_fault_handler() __attribute__((weak, alias("default_handler")));;
void bus_fault_handler() __attribute__((weak, alias("default_handler")));;
void usage_fault_handler() __attribute__((weak, alias("default_handler")));;



static unsigned long stacktop[256];

void (* vector[])() __attribute__((section(".vectors"))) = 
{
	(void(*)()) ((unsigned long) stacktop + sizeof(stacktop)),
	&reset_handler,
	&NMI_handler,
	&hard_fault_handler,
	&memory_managment_fault_handler,
	&bus_fault_handler,
	&usage_fault_handler
};


void reset_handler()
{
	unsigned int data_size = (unsigned char*) &_E_data - (unsigned char*) &_S_data;
	unsigned char * data_src = (unsigned char *) &_E_text;
	unsigned char * data_des = (unsigned char*) &_S_data;
	int i;

	for(i=0; i<data_size; i++)
		*((unsigned char*) data_des++) = *((unsigned char*) data_src++);

	unsigned int bss_size = (unsigned char*) &_E_bss - (unsigned char*) &_S_bss;
	unsigned char * bss_des = (unsigned char*) &_S_bss;

	for(i=0; i<bss_size; i++)
		*((unsigned char*) bss_des++) = (unsigned char) 0;

	main();

}

