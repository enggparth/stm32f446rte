/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: May 3, 2019
 *      Author: Parth
 *
 * ****************************************************************
 *
 *
 *
 *
 *
 *
 *  The GPIO driver source file should contain GPIO driver.h file
 */

#include "stm32f446xx_gpio_driver.h" // driver specific header file


/*
 *  Peripheral Clock Setup
 */

void GPIO_PeriClockControl(GPIO_RefDef_t *pGPIOx, uint8_t EnorDi){

}

/* Init and De- init */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

}


void GPIO_DeInit(GPIO_RefDef_t *pGPIOx){


}

/* Data Read and  Write */

uint8_t GPIO_ReadFromInputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber){

}

uint16_t GPIO_ReadFromInputPort(GPIO_RefDef_t *pGPIOx){

}
void GPIO_WriteToOutputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

}


void GPIO_WriteToOutputPort(GPIO_RefDef_t *pGPIOx,  uint16_t Value){

}

void GPIO_ToggleOutputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber){

}

/* IRQ and configuration and ISR handling   */


void GPIO_IRQConfig(uint8_t IRQNUMBER, uint8_t IRQPriority, uint8_t EnorDi){

}
void GPIO_IRQHandling(uint8_t PinNumber) {


}


















