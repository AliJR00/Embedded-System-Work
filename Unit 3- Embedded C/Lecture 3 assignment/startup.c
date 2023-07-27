extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
extern unsigned int stack_top;

void reset_handler(void);

extern void main(void);
void default_handler(void)
{
	reset_handler();
}

void hmi_handler(void) __attribute__((weak, alias("default_handler")));;
void h_fault_handler(void) __attribute__((weak, alias("default_handler")));;
void mm_fault_handler(void) __attribute__((weak, alias("default_handler")));;
void bus_fault(void) __attribute__((weak, alias("default_handler")));;
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));;



unsigned int vectors[] __attribute__((section(".vectors"))) = 
{
	(unsigned int) &stack_top,
	(unsigned int) &reset_handler,
	(unsigned int) &hmi_handler,
	(unsigned int) &h_fault_handler,
	(unsigned int) &mm_fault_handler,
	(unsigned int) &bus_fault,
	(unsigned int) &usage_fault_handler

};


void reset_handler()
{
	unsigned int data_size = (unsigned char*) &_E_data - (unsigned char*) &_S_data;
	unsigned char* data_src = (unsigned char*) &_E_text;
	unsigned char* data_des = (unsigned char*) &_S_data;

	int i;
	for(i=0; i<data_size; i++)	
	*((unsigned char*) data_des++) = *((unsigned char*) data_src++);

	unsigned int bss_size = (unsigned char*) &_E_bss - (unsigned char*) &_S_bss;
	unsigned char* bss_des = (unsigned char*) &_S_bss;

	
	for(i=0; i<bss_size; i++)	
	*((unsigned char*) bss_des++) = (unsigned char) 0;

	main();
}
