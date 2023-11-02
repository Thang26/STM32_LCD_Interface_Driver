#include <common.h>
#include <timer_init.h>

void LED_FLASH_TIMER_INIT(void){

    APB1_TIMERx_ENABLE(TIMER_3_EN);
    TIM3->PSC = 1600 - 1;
    TIM3->ARR = 5000 - 1;
    TIM3->CNT = 0;
    TIM3->CR1 = 1;

}