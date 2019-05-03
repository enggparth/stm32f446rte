/*
 * stm32f446xx.h
 *
 *  Created on: Apr 23, 2019
 *      Author: Parth
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include<stdint.h>   // For using uint32_t data type
#define __vo volatile
/*
 * base addresses of Flash and SRAM memories
 *
 * By default(compiler) these number are considered as signed number
 * but addresses can't be signed they are always unsigned
 * Two ways to type casting the addresses (these are unsigned int)
 * 				1) (u_int32) 0x08000000
 * 				2) 0x08000000U
 *
 *
 * 	Calculation of SRAM2 from SRAM1
 * 	112Kb  = 112*1024 bytes == 114688 in (DEC) or 1C000(HEX)
 * 	Therefore SRAM2 = SRAM1_BASEADDR + 1C000 = 0x2001C000
 */

#define FLASH_BASEADDR				0x08000000U		/* The flash memory base address */
#define SRAM1_BASEADDR				0x20000000U 	/* total size of SRAM1 112Kb*/
#define SRAM2_BASEADDR				0x2001C000U		/* total size of SRAM2 6Kb*/
#define ROM							0x1FFF0000U
#define OTP_BASEADDR				0x1FFF7800U
#define SRAM 						SRAM1_BASEADDR  //SRAM 1 is called as main SRAM & SRAM  2 we are not using



/*
 * Define the base addresses of various bus domain (AHBx  and APBx)
 *
 * Check the starting addresses of peripherals  as well as which register is mapped to the starting of the addresses
 * eg : in our case TIM2 peripheral mapped to the starting of the peripherals bus.
 * Also find the which REGISTER is mapped to these addresses.
 *
 */

#define PERIPH_BASEADDR						0x40000000U
#define APB1PERIPH_BASEADDR					PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR					0x40010000U
#define AHB1PERIPH_BASEADDR					0x40020000U
#define AHB2PERIPH_BASEADDR					0x50000000U





/*
 *
 * Base addresses of peripherals which are hanging in AHB1 Bus
 *
 */
#define GPIOA_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0000)
#define	GPIOB_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1C00)

#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x3800)


/*
 *
 * Base addresses of peripherals which are hanging in APB1 Bus
 *
 */

#define I2C1_BASEADDR 					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR 					(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR 					(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR 					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR 					(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR 				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR 				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR 					(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR 					(APB1PERIPH_BASEADDR + 0x5000)



/*
 *
 * Base addresses of peripherals which are hanging in APB2 Bus
 *
 *
 */
#define EXTI_BASEADDR 						(APB2PERIPH_BASEADDR + 0x3C00)

#define SYSCFG_BASEADDR 					(APB2PERIPH_BASEADDR + 0x3800)

#define SPI1_BASEADDR 						(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR 						(APB2PERIPH_BASEADDR + 0x3400)

#define USART1_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1400)



/*
 *
 *********************************** Structuring Peripherals registers details*********************************************
 * Note: There is need to create the C structure for every peripherals which contains all the registers
 * Note : Registers of a peripherals are specific to MCU
 * Please chech your Device RM
 *
 * You have to use volatile member qualifier because some register may be volatile in nature
 */

/*
 * Structure for GPIO
 * In this file we are only working with GPIO so not include the structure for other peripherals
 */
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDER;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSPR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];        // AFR[0] = is  GPIO alternate function HIGH register and AFR[1] is GPIO alternate function HIGH register


}GPIO_RefDef_t;

/*
 * Type casting for different GPIO port (eg..A.....H)
 * Peripherals definitions (peripheral base addresses typecasted to xxx_RefDef_t)
 */


#define GPIOA 					((GPIO_RefDef_t*)GPIOA_BASEADDR)
#define GPIOB					((GPIO_RefDef_t*)GPIOB_BASEADDR)
#define GPIOC					((GPIO_RefDef_t*)GPIOC_BASEADDR)
#define GPIOD					((GPIO_RefDef_t*)GPIOD_BASEADDR)
#define GPIOE					((GPIO_RefDef_t*)GPIOE_BASEADDR)
#define GPIOF					((GPIO_RefDef_t*)GPIOF_BASEADDR)
#define GPIOG					((GPIO_RefDef_t*)GPIOG_BASEADDR)
#define GPIOH					((GPIO_RefDef_t*)GPIOH_BASEADDR)


/*
 * PEripherals clock control
 * Structure for RCC control
 */

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLL_CFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1_RSTR;
	__vo uint32_t AHB2_RSTR;
	__vo uint32_t AHB3_RSTR;
	uint32_t RESERVED0;
	__vo uint32_t APB_RSTR[2];
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1_ENR;
	__vo uint32_t AHB2_ENR;
	__vo uint32_t AHB3_ENR;
	__vo uint32_t RESERVED2;
	__vo uint32_t APB1_ENR;
	__vo uint32_t APB2_ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t AHB1_LPENR;
	__vo uint32_t AHB2_LPENR;
	__vo uint32_t AHB3_LPENR;
	uint32_t RESERVED4;
	__vo uint32_t APB1_LPENR;
	__vo uint32_t APB2_LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLL_I2_SCFGR;
	__vo uint32_t PLL_SAI_CFGR;
	__vo uint32_t DCK_CFGR;
	__vo uint32_t CK_GATENR;
	__vo uint32_t DCK_CFGR2;

}RCC_RegDef_t;

#define RCC				((RCC_RegDef_t*)RCC_BASEADDR)


/*
 * Clock enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 0) )
#define GPIOB_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 1) )
#define GPIOC_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 2) )
#define GPIOD_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 3) )
#define GPIOE_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 4) )
#define GPIOF_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 5) )
#define GPIOG_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 6) )
#define GPIOH_PCLK_ENB() 		( RCC->AHB1_ENR |= (1 << 7) )

/*
 * Clock enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_ENB 			( RCC->APB1_ENR |= (1 << 21) )
#define I2C2_PCLK_ENB			( RCC->APB1_ENR |= (1 << 22) )
#define I2C3_PCLK_ENB			( RCC->APB1_ENR |= (1 << 23) )


/*
 * Clock enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_ENB			(RCC->APB2_ENR |= (1 << 12 )
#define SPI2_PCLK_ENB			(RCC->APB1_ENR |= (1 << 14 )
#define SPI3_PCLK_ENB			(RCC->APB1_ENR |= (1 << 15 )
#define SPI4_PCLK_ENB			(RCC->APB2_ENR |= (1 << 13 )
/*
 * Clock enable Macros for USARTx peripherals
 */


/*
 * Clock enable Macros for SYSCFG peripherals
 */



/*
 * Clock disable  Macros for GPIOx peripherals
 */

/*
 * Clock disable  Macros for I2Cx peripherals
 */

/*
 * Clock disable  Macros for SPIx peripherals
 */

/*
 * Clock disable  Macros for USARTx peripherals
 */

/*
 * Clock disable  Macros for SYSCFG peripherals
 */


#endif /* INC_STM32F446XX_H_ */
