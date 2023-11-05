#include <common.h>
#include <timer_init.h>

/*
 *  Timer init function used by the other LED's flashing functions.
 *  Default SYSCLK is 62.5ns * (PSC) * (ARR)
 */
void LED_FLASH_TIMER_INIT(UINT16 PSC_Div_Val, UINT16 ARR_Div_Val){

    /* Configs timing parameters for the timer */
    APB1_TIMERx_ENABLE(TIMER_3_EN); //Enables clock for timer.
    TIM3->PSC = PSC_Div_Val - 1;
    TIM3->ARR = ARR_Div_Val - 1;
    TIM3->CNT = 0;                  //Initially clears the COUNTER within timer.
    TIM3_FLAG_CLEAR;                //Ensures UIE flag for TIM3 is cleared upon init.
    TIM3->CR1 |= (1U << 7);         //Turns on ARR Preload Buffer

    /* Configs IRQ for the timer */
    TIM3_IRQ_EN;                    //Configs TIM3 to trigger IRQ upon UIE event.
    NVIC_EnableIRQ(TIM3_IRQn);      //Enable IRQ in NVIC

    /* Set the timer in motion */
    TIM3_START;                     //Enables the timer.

}

void LED_FLASH_TIMER_UPDATE_VAL(UINT16 ARR_Div_Val){

    TIM3->ARR = ARR_Div_Val - 1;

}

/*
 *  250ms       PSC = 1600, ARR = 2500
 *  500ms       PSC = 1600, ARR = 5000
 *  1000ms      PSC = 1600, ARR = 10000
 */

/*
 * ARR Preload Buffer ensures that any updates to the ARR register
 * will be applied AFTER the current timer cycle has finished.
 */