/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: May 3, 2019
 *      Author: Parth
 */

/*
 * GPIO Handle and Configuration structures
 * It is used by the user application
 *
 * GPIOx Peripherals contain following API
 * 		-> GPIO Port Name
 * 		-> GPIO Pin number
 * 		-> GPIO mode
 * 		-> GPIO speed
 * 		-> GPIO output type
 * 		-> GPIO Pull up-pull down
 * 		-> GPIO Alt. fun mode
 *
 *
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"   //MCU specific header files

/*
 * ***********************************************
 * GPIO Handle and Configuration structures		 *
 * It is used by the user application			 *
 * 												 *
 * GPIOx Peripherals contain following API		 *
 * 		-> GPIO Port Name						 *
 * 		-> GPIO Pin number  					 *
 * 		-> GPIO mode							 *
 * 		-> GPIO speed							 *
 * 		-> GPIO output type						 *
 * 		-> GPIO Pull up-pull down				 *
 * 		-> GPIO Alt. fun mode					 *
 *************************************************
 */
typedef struct
{

	uint8_t GPIO_PinNumber;  /* uint8(one byte) is sufficient because pin number range from 0 to 15    */
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;




/*
 ********************************************************************************************
 * Therefore driver layers should give a configuration structure to the user application	*
 * 		-> Handle structure																	*
 * 		-> configuration structure															*
 ********************************************************************************************
 */

typedef struct
{
	// pointer to hold the base address of the GPIO peripherals
	GPIO_RefDef_t *pGPIOx; 			             /*  This holds the base address of the GPIO port to which the pin belongs  */
	GPIO_PinConfig_t GPIO_PinConfig;              /*  This holds the GPIO pin configuration settings */

}GPIO_Handle_t;





/* GPIO driver APIs Requirement are as follow
 *
 * 			-> GPIO initialization
 * 			-> GPIO Port CLK EN/DIS
 * 			-> Read from a GPIO pin
 * 			-> Write to a GPIO pin
 * 			-> Configure alternate fun
 * 			-> Interrupt handling	(EN/DNB ,change priority etc)
 */


/************************************************************************
 *
 * 					API supported by this driver
 * 		For more information about APIs check the function definitions
 *
 ************************************************************************/

/*
 *  Peripheral Clock Setup
 */

void GPIO_PeriClockControl(GPIO_RefDef_t *pGPIOx, uint8_t EnorDi);

/* Init and De- init */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RefDef_t *pGPIOx);    // In RCC Section Peripherals Reset Register is used

/* Data Read and  Write */

uint8_t GPIO_ReadFromInputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RefDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RefDef_t *pGPIOx,  uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber);

/* IRQ and configuration and ISR handling   */


void GPIO_IRQConfig(uint8_t IRQNUMBER, uint8_t IRQPriority, uint8_t EnorDi); 					 //For enable ,setting priority etc
void GPIO_IRQHandling(uint8_t PinNumber);  																	 /* When ever interrupt occur sp that user can call this function to process interrupt */
















#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
