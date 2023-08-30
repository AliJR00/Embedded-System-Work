

#ifndef GPIO_GPIO_DRIVER_H_
#define GPIO_GPIO_DRIVER_H_
#include "stm32f103c6_Device_Header.h"

typedef struct{
	uint16_t GPIO_PinNumber;    //determines which pin to be configured
					        	//this parameter has values according to @ref GPIO Pin Numbers
	uint8_t GPIO_PinMode;  		//determines if the pin is output or input
								// this parameter has value according to @ref GPIO Pin Mode
	uint8_t GPIO_PinSpeed;		//determines the output speed for the pin
								//the parameter has values according to @ref GPIO Pin Speed
}Pinconfig;




//@ref GPIO Pin Numbers
#define GPIO_PinNum0   (uint16_t)1<<0
#define GPIO_PinNum1   (uint16_t)1<<1
#define GPIO_PinNum2   (uint16_t)1<<2
#define GPIO_PinNum3   (uint16_t)1<<3
#define GPIO_PinNum4   (uint16_t)1<<4
#define GPIO_PinNum5   (uint16_t)1<<5
#define GPIO_PinNum6   (uint16_t)1<<6
#define GPIO_PinNum7   (uint16_t)1<<7
#define GPIO_PinNum8   (uint16_t)1<<8
#define GPIO_PinNum9   (uint16_t)1<<9
#define GPIO_PinNum10   (uint16_t)1<<10
#define GPIO_PinNum11   (uint16_t)1<<11
#define GPIO_PinNum12   (uint16_t)1<<12
#define GPIO_PinNum13   (uint16_t)1<<13
#define GPIO_PinNum14   (uint16_t)1<<14
#define GPIO_PinNum15   (uint16_t)1<<15

//@ref GPIO Pin Mode
#define GPIO_INPUT_ANALOG		0
#define GPIO_INPUT_FLOATING		1
#define GPIO_INPUT_PU			2			//INPUT PULL UP
#define GPIO_INPUT_PD			3			//INPUT PULL DOWN
#define GPIO_OUTPUT_PUSHPULL	4
#define GPIO_OUTPUT_OPENDRAIN	5
#define GPIO_OUTPUT_AF_PUSHPULL	6			//AFIO OUTPUT
#define GPIO_OUTPUT_AF_OPENDRAIN	7			//AFIO OUTPUT
#define GPIO_OUTPUT_AF_INPUT	8			//AFIO INPUT

//@ref GPIO Pin Speed
#define GPIO_SPEED_10M   1 				//Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M    2				//Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M   3				//Output mode, max speed 50 MHz.

//@ref PIN READING/Writing
#define GPIO_PIN_ON		1
#define GPIO_PIN_OFF	0

//@ref lock state
#define GPIO_LOCK_ENABLED 1
#define GPIO_LOCK_ABORTED 0



void MCAL_GPIO_Init(GPIO_typedef* GPIOx, Pinconfig* PinConfig);
void MCAL_GPIO_DeInit(GPIO_typedef* GPIOx);

void MCAL_GPIO_WRITEPIN(GPIO_typedef* GPIOx, uint16_t PinNum, uint8_t value); //the written values according to @ref PIN READING/Writing
																			//The PinNum is put according to @ref GPIO Pin Numbers
void MCAL_GPIO_WRITEPORT(GPIO_typedef* GPIOx, uint8_t value);

uint8_t MCAL_GPIO_READPIN(GPIO_typedef* GPIOx, uint16_t PinNum);      //returned values according to @ref PIN READING/Writing

uint16_t MCAL_GPIO_READPORT(GPIO_typedef* GPIOx);

void MCAL_GPIO_TOGGLEPIN(GPIO_typedef* GPIOx, uint16_t PinNum);

uint8_t MCAL_GPIO_PINLOCK(GPIO_typedef* GPIOx, uint16_t PinNum);    //returned values according to @ref lock state



//GPIO Clock enabling Macros
#define GPIOA_CLK_EN()		RCC->APB2ENR |= 1<<2
#define GPIOB_CLK_EN()		RCC->APB2ENR |= 1<<3
#define GPIOC_CLK_EN()		RCC->APB2ENR |= 1<<4
#define GPIOD_CLK_EN()		RCC->APB2ENR |= 1<<5





#endif /* GPIO_GPIO_DRIVER_H_ */
