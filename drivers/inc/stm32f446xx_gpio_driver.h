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

	uint8_t GPIO_PinNumber;                 /*|< Possible values @GPIO_PIN_NUMBER >|*/
	uint8_t GPIO_PinMode;					/*|< Possible values @GPIO_PIN_MODES >|*/
	uint8_t GPIO_PinSpeed;					/*|< Possible values @GPIO_PIN_SPEED >|*/
	uint8_t GPIO_PinPuPdControl;			/*|< Possible values @GPIO_PIN_PU_PD >|*/
	uint8_t GPIO_PinOPType;					/*|< Possible values @GPIO_PIN_OUTPUT >|*/
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


/*
 * @GPIO_PIN_NUMBER
 * GPIO pin numbers
 */

#define GPIO_PIN_NO_0					0
#define GPIO_PIN_NO_1					1
#define GPIO_PIN_NO_2					2
#define GPIO_PIN_NO_3					3
#define GPIO_PIN_NO_4					4
#define GPIO_PIN_NO_5					5
#define GPIO_PIN_NO_6					6
#define GPIO_PIN_NO_7					7
#define GPIO_PIN_NO_8					8
#define GPIO_PIN_NO_9					9
#define GPIO_PIN_NO_10					10
#define GPIO_PIN_NO_11					11
#define GPIO_PIN_NO_12					12
#define GPIO_PIN_NO_13					13
#define GPIO_PIN_NO_14					14
#define GPIO_PIN_NO_15					15


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */

//Non Interrupt modes
#define GPIO_MODE_IN					0
#define GPIO_MODE_OUT					1
#define GPIO_MODE_ALTFN					2
#define GPIO_MODE_ANALOG 				3

//Interrupt modes
#define GPIO_MODE_IT_FT					4 			 //Input Falling edge Trigger interrupt mode (FT-> Falling Trigger)
#define GPIO_MODE_IT_RT					5			 //Input Rising edge Trigger interrupt mode (RT-> RisingTrigger	)
#define GPIO_MODE_IT_RFT				6			 //Input Falling and Rising edge Trigger interrupt mode (RFT-> Rising and Falling  Trigger)


/*
 * @GPIO_PIN_OUTPUT
 * GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP     			0
#define GPIO_OP_TYPE_OD					1



/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speed type
 */

#define GPIO_SPEED_LOW							0 		// Output Low speed
#define GPIO_SPEED_MEDIUM						1		// Output Medium speed
#define GPIO_SPEED_HIGH							2		// Output High speed
#define GPIO_SPEED_FAST							3		// Output Fast speed

/*
 * @GPIO_PIN_PU_PD
 * GPIO pin possible Pull up AND Pull Down configuration macros
 */

#define GPIO_NO_PUPD							0    //No pull up pul down
#define GPIO_PIN_PU								1	 // Pull up
#define GPIO_PIN_PD								2	 // Pull down

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
