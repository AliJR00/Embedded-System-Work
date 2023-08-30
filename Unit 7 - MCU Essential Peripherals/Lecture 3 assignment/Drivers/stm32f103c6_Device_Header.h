

#ifndef STM32F103C6_DEVICE_HEADER_H_
#define STM32F103C6_DEVICE_HEADER_H_


//includes
#include "stdint.h"

//Base addresses for AHB Peripherals
//RCC
#define RCC_BASE 0x40021000UL


//=============================

//Base addresses for APB2 Peripherals

//GPIO
//A and B are fully included
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
//C and D are partially included
#define GPIOC_BASE 0x40011000
#define GPIOD_BASE 0x40011400

//AFIO
#define AFIO_BASE 0x40010000





//AFIO REGISTERS
typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_typedef;



//RCC REGISTERS
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_typedef;

//GPIO REGISTERS
typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_typedef;




//GPIO INSTANTS
#define GPIOA		((GPIO_typedef*) GPIOA_BASE)
#define GPIOB		((GPIO_typedef*) GPIOB_BASE)
#define GPIOC		((GPIO_typedef*) GPIOC_BASE)
#define GPIOD		((GPIO_typedef*) GPIOD_BASE)

#define RCC			((RCC_typedef*) RCC_BASE)

#define AFIO		((AFIO_typedef*) AFIO_BASE)




#endif /* STM32F103C6_DEVICE_HEADER_H_ */
