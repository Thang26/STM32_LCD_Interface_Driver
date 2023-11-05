/*
 * user_interface.c
 *
 *  Created on: Nov 03, 2023
 *      Author: Thang Pham
 * 
 *  The STM32F446RE Nucleo board has an on-board LED.
 *  It is associated with GPIOA, Pin 5.
 */

#include <common.h>
#include <port_init.h>
#include <timer_init.h>

/*
 *  Functions to interface with the onboard LED (GPIOA Pin 5)
 */

void USER_LED_SET(void){

    GPIOA_BSRR_SEL(PIN_5, BSRR_PIN_SET);
}

void USER_LED_CLEAR(void){

    GPIOA_BSRR_SEL(PIN_5, BSRR_PIN_CLEAR);
}

void USER_LED_TOGGLE(void){

    GPIOA_TOGGLE_PIN(PIN_5);
}

void USER_LED_INIT(void){

    RCC_GPIO_CLK_ENABLE(GPIOA_CLK_EN);
    GPIOA_MODER_SEL(PIN_5, OUTPUT_SEL);
    USER_LED_CLEAR();
}

void USER_LED_BLINK_INIT(void){

    USER_LED_INIT();
    LED_FLASH_TIMER_INIT(1600, 10000);  //Sets default to blink at 1 Hz
}

void USER_LED_SLOW_BLINK(void){

    LED_FLASH_TIMER_UPDATE_VAL(10000);
}

void USER_LED_FAST_BLINK(void){

    LED_FLASH_TIMER_UPDATE_VAL(2500);
}