#include <common.h>
#include <port_init.h>

void USER_LED_INIT(void){

    RCC_GPIO_CLK_ENABLE(GPIOA_CLK_EN);
    GPIOA_MODER_SEL(PIN_5, OUTPUT_SEL);
    GPIOA_BSRR_SEL(PIN_5, BSRR_PIN_CLEAR);

}
void USER_LED_SET(void){

    GPIOA_BSRR_SEL(PIN_5, BSRR_PIN_SET);
}

void USER_LED_CLEAR(void){

    GPIOA_BSRR_SEL(PIN_5, BSRR_PIN_CLEAR);
}

void USER_LED_FLASH(void){


    
}