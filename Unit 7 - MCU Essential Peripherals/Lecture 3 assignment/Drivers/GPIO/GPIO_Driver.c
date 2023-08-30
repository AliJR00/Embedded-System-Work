#include "GPIO_Driver.h"





//converting the pin number to the corresponding location Macro

uint8_t PinLocationF(uint16_t x)
{
	uint8_t count = 1, co = 1, flag = 0;

	while(count<16)
	{
		if(count>7 && flag == 0)
		{
			co=0;
			flag = 1;
		}
		x = x>>1;
		if(x == 1)
		{
			return co*4;
		}

		count++;
		co++;
	}
	return 0;

}


/*
 * @Fn				- MCAL_GPIO_Init
 * @brief 			- Initializes the GPIO Pin according to the parameters in Pinconfig
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @param [in] 		- Pin : contains the configuration for the pin.
 * @retval			- None
 */

void MCAL_GPIO_Init(GPIO_typedef* GPIOx, Pinconfig* Pin)
{
	volatile uint32_t* configregister = (void*)0;

	if((Pin->GPIO_PinNumber) < GPIO_PinNum8)
	{
		configregister = &GPIOx->CRL;
	}
	else
	{
		configregister = &GPIOx->CRH;
	}

	if(Pin->GPIO_PinMode == GPIO_INPUT_ANALOG || Pin->GPIO_PinMode == GPIO_INPUT_FLOATING || Pin->GPIO_PinMode == GPIO_INPUT_PD || Pin->GPIO_PinMode == GPIO_INPUT_PU)
	{
		(*configregister) &= ~(0xF << PinLocationF(Pin->GPIO_PinNumber));
		(*configregister) |= (Pin->GPIO_PinMode << (PinLocationF(Pin->GPIO_PinNumber)))<<2;

		if(Pin->GPIO_PinMode == GPIO_INPUT_PD)
		{
			(*configregister) &= ~(0xF << PinLocationF(Pin->GPIO_PinNumber));
			(*configregister) |= ((Pin->GPIO_PinMode -1) << (PinLocationF(Pin->GPIO_PinNumber)))<<2;
			GPIOx->ODR &= ~(Pin->GPIO_PinNumber);
		}
		else if(Pin->GPIO_PinMode == GPIO_INPUT_PU)
		{
			GPIOx->ODR |= Pin->GPIO_PinNumber;
		}
	}


	else if(Pin->GPIO_PinMode == GPIO_OUTPUT_AF_INPUT)
	{
		(*configregister) &= ~(0xF << PinLocationF(Pin->GPIO_PinNumber));
		(*configregister) |= ((Pin->GPIO_PinMode - 7) << (PinLocationF(Pin->GPIO_PinNumber)))<<2;
	}


	else if(Pin->GPIO_PinMode == GPIO_OUTPUT_PUSHPULL || Pin->GPIO_PinMode == GPIO_OUTPUT_OPENDRAIN || Pin->GPIO_PinMode == GPIO_OUTPUT_AF_PUSHPULL || Pin->GPIO_PinMode == GPIO_OUTPUT_AF_OPENDRAIN)
	{
		(*configregister) &= ~(0xF << PinLocationF(Pin->GPIO_PinNumber));
		(*configregister) |= (((Pin->GPIO_PinMode)-4) << (PinLocationF(Pin->GPIO_PinNumber)))<<2;
		(*configregister) |= (Pin->GPIO_PinSpeed) << PinLocationF(Pin->GPIO_PinNumber);
	}

}




/*
 * @Fn				- MCAL_GPIO_DeInit
 * @brief 			- reset the GPIO Pin according to the parameters in Pinconfig
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @retval			- None
 */


void MCAL_GPIO_DeInit(GPIO_typedef* GPIOx)
{
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= 1<<2;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= 1<<3;
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
		{
			RCC->APB2RSTR |= 1<<3;
			RCC->APB2RSTR &= ~(1<<3);
		}
	else if(GPIOx == GPIOD)
		{
			RCC->APB2RSTR |= 1<<4;
			RCC->APB2RSTR &= ~(1<<4);
		}
}

/*
 * @Fn				- MCAL_GPIO_WRITEPIN
 * @brief 			- writes on the GPIO Pin
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @param [in] 		- PinNum: The GPIO pin to be written on
 * @param [in] 		- Value: The value that will be written on the pin
 * @retval			- None
 *
 */


void MCAL_GPIO_WRITEPIN(GPIO_typedef* GPIOx, uint16_t PinNum, uint8_t value)
{
	if(value == GPIO_PIN_ON)
	{
		GPIOx->BSRR |= PinNum;
	}
	else if(value == GPIO_PIN_OFF)
	{
		GPIOx->BSRR |= (PinNum) << 16;
	}
}

/*
 * @Fn				- MCAL_GPIO_WRITEPORT
 * @brief 			- writes on the GPIO Port
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @param [in] 		- Value: The value that will be written on the port
 * @retval			- None
 *
 */
void MCAL_GPIO_WRITEPORT(GPIO_typedef* GPIOx, uint8_t value)
{
	GPIOx->ODR = value;
}


/*
 * @Fn				- MCAL_GPIO_READPIN
 * @brief 			- reads the GPIO Pin
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @param [in] 		- PinNum: The GPIO pin to be read
 * @retval			- the value of the pin
 *
 */



uint8_t MCAL_GPIO_READPIN(GPIO_typedef* GPIOx, uint16_t PinNum)
{
	if(((GPIOx->IDR) & PinNum) != 0)
	{
		return GPIO_PIN_ON;
	}
	else
	{
		return GPIO_PIN_OFF;
	}
}


/*
 * @Fn				- MCAL_GPIO_READPORT
 * @brief 			- reads the GPIO Port
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @retval			- the value of the port
 *
 */

uint16_t MCAL_GPIO_READPORT(GPIO_typedef* GPIOx)
{
	return (uint16_t)GPIOx->IDR;
}

/*
 * @Fn				- MCAL_GPIO_TOGGLEPIN
 * @brief 			- toggles the GPIO Pin
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @param [in] 		- PinNum: The GPIO pin to be toggled
 * @retval			- None
 *
 */

void MCAL_GPIO_TOGGLEPIN(GPIO_typedef* GPIOx, uint16_t PinNum)
{
	GPIOx->ODR ^= PinNum;
}

/*
 * @Fn				- MCAL_GPIO_PINLOCK
 * @brief 			- locks the GPIO Pin
 * @param [in] 		- GPIOx: where x can be A to E depending on device used to select the GPIO peripheral
 * @param [in] 		- PinNum: The GPIO pin to be locked
 * @retval			- None
 *
 */


uint8_t MCAL_GPIO_PINLOCK(GPIO_typedef* GPIOx, uint16_t PinNum)
{
	uint8_t temp;

	GPIOx->LCKR |= PinNum;

	GPIOx->LCKR |= 1<<16;

	GPIOx->LCKR &= ~(1<<16);

	GPIOx->LCKR |= 1<<16;

	temp = 	(GPIOx->LCKR & 1<<16);


	if(	GPIOx->LCKR & 1<<16)
	{
		return GPIO_LOCK_ENABLED;
	}
	else
	{
		return GPIO_LOCK_ABORTED;
	}



}
