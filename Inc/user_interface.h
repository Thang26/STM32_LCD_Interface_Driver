/*
 * user_interface.h
 *
 *  Created on: Nov 04, 2023
 *      Author: Thang Pham
 * 
 *  Header file associated with the user_interface.c
 *  
 */

/*
 *  Function prototype declaration
 */

void USER_LED_CLEAR(void);
void USER_LED_SET(void);
void USER_LED_TOGGLE(void);
void USER_LED_INIT(void);
void USER_LED_BLINK_INIT(void);
void USER_LED_SLOW_BLINK(void);
void USER_LED_FAST_BLINK(void);

/*
 *  Macro for User LED Interface
 */

#define USER_LED_ON    0
#define USER_LED_OFF  16
#define USER_LED_CONFIG(PIN_NUM, PIN_SET_CLEAR)    GPIOA_BSRR_SEL(PIN_NUM, PIN_SET_CLEAR)
#define USER_LED_CONFIG_TOGGLE(PIN_NUM)            GPIOA_TOGGLE_PIN(PIN_NUM)