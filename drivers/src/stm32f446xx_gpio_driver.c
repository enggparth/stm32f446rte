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
/********************************************************************
 *
 *  @fn									- GPIO_PeriClockControl
 *
 *  @breif								- This function enables or disable the peripherals clock for given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							- ENABLE or DISABLE macros
 *  @param[in]							-
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_PeriClockControl(GPIO_RefDef_t *pGPIOx, uint8_t EnorDi){

}

/* Init and De- init */
/********************************************************************
 *
 *  @fn									- GPIO_Init
 *
 *  @breif								- This function initializes the peripherals clock for given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							-
 *  @param[in]							-
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

}



/********************************************************************
 *
 *  @fn									- GPIO_DeInit
 *
 *  @breif								- This function de-initializes the peripherals clock for given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							-
 *  @param[in]							-
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_DeInit(GPIO_RefDef_t *pGPIOx){


}

/* Data Read and  Write */
/********************************************************************
 *
 *  @fn									- GPIO_ReadFromInputPin
 *
 *  @breif								- This function reads from the input pin of  given  GPIOx pin
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							- Pin number
 *  @param[in]							-
 *
 *  @return 							-status of given pin
 *
 *  @note								-none
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber){

}



/********************************************************************
 *
 *  @fn									- GPIO_ReadFromInputPort
 *
 *  @breif								- This function reads from the input port of  given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							-
 *  @param[in]							-
 *
 *  @return 							-status of given GPIOx port
 *
 *  @note								-none
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RefDef_t *pGPIOx){

}




/********************************************************************
 *
 *  @fn									- GPIO_WriteToOutputPin
 *
 *  @breif								- This function write to the output pin of given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							-Pin number
 *  @param[in]							-Value to be written
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_WriteToOutputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

}



/********************************************************************
 *
 *  @fn									- GPIO_WriteToOutputPort
 *
 *  @breif								- This function write to the output port of given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							- Value to be written
 *  @param[in]							-
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_WriteToOutputPort(GPIO_RefDef_t *pGPIOx,  uint16_t Value){

}



/********************************************************************
 *
 *  @fn									- GPIO_ToggleOutputPin
 *
 *  @breif								- This function toggle the output pin of given  GPIOx port
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							- Pin number
 *  @param[in]							-
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_ToggleOutputPin(GPIO_RefDef_t *pGPIOx, uint8_t PinNumber){

}

/* IRQ and configuration and ISR handling   */

/********************************************************************
 *
 *  @fn									- GPIO_IRQConfig
 *
 *  @breif								- This function configure the IRQ like enable or disable ,priority
 *
 *  @param[in]							- Base addresses of GPIOx
 *  @param[in]							- IRQ priority
 *  @param[in]							- Enable or Disable macros
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_IRQConfig(uint8_t IRQNUMBER, uint8_t IRQPriority, uint8_t EnorDi){

}

/********************************************************************
 *
 *  @fn									- GPIO_IRQHandling
 *
 *  @breif								- This function Handle IRQ request
 *
 *  @param[in]							- IRQ pin number
 *  @param[in]							-
 *  @param[in]							-
 *
 *  @return 							-none
 *
 *  @note								-none
 */
void GPIO_IRQHandling(uint8_t PinNumber) {


}


















