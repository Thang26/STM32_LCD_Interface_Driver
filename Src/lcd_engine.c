/*
 * lcd_engine.c
 *
 *  Created on: Nov 05, 2023
 *      Author: Thang Pham
 * 
 *  File responsible for containing the general functions to
 *  interface with the LCD.
 */

#include <timer_init.h>

void LCD_COMMAND_NO_POLL(void){



}

void ENABLE_LATCH(void){



}

void LCD_INSTRUCTION_STARTUP(void){
    
    LCD_DELAY_OPM_TIMER_INIT(300);
    while(!(TIM2_COMPLETE_EVENT)){}
    //TODO Command
    LCD_DELAY_OPM_TIMER_UPDATE(100);
    while(!(TIM2_COMPLETE_EVENT)){}
    //TODO Command
    LCD_DELAY_OPM_TIMER_UPDATE(10);
    while(!(TIM2_COMPLETE_EVENT)){}
    //TODO Command


}