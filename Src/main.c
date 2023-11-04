/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <common.h>
#include <port_init.h>
#include <user_interface.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	__disable_irq();
	
	// if(LCD_PORT_INIT()){
	// 	//something
	// }
	// else{
	// 	//The init routine failed, best we can do is try again.
	// 	NVIC_SystemReset();
	// }

	USER_LED_SLOW_BLINK();

	__enable_irq();

	  while(1){

	  }
}
