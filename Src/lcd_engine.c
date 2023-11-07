/*
 * lcd_engine.c
 *
 *  Created on: Nov 05, 2023
 *      Author: Thang Pham
 * 
 *  File responsible for containing the general functions to
 *  interface with the LCD.
 */

#include <common.h>
#include <port_init.h>
#include <timer_init.h>
#include <lcd_engine.h>

/* 
 *  Enable Pulse Duration: 0.1ms
 *  WARNING: Cannot use this function prior to LCD_INSTRUCTION_STARTUP call.
 *  TIM2 is INITIALIZED within that function, which this function uses.
 */
void ENABLE_LATCH_PULSE(void){

    ENABLE_SET;
    LCD_DELAY_OPM_TIMER_UPDATE(2);
    while(!(TIM2_COMPLETE_EVENT)){}
    ENABLE_CLEAR;

    //TODO Implement warning if LCD_INSTRUCTION_STARTUP has not been called yet.
    //This function returns obsolete if so.
}

void LCD_READY_POLL(void){
    
    UINT8 status;

    BUSY_PIN_PROCESS_READ;
    LCD_RS_CONFIG(RS_SET_TO_COMMAND)
    LCD_RW_CONFIG(RW_SET_TO_READ)

    do {
        ENABLE_SET;

        LCD_DELAY_OPM_TIMER_UPDATE(2);
        while(!(TIM2_COMPLETE_EVENT)){}

        status = GPIOC->IDR;
        ENABLE_CLEAR;

        LCD_DELAY_OPM_TIMER_UPDATE(2);
        while(!(TIM2_COMPLETE_EVENT)){}

    } while (status & 0x80);

    /* Return to default write configuration */
    LCD_RW_CONFIG(RW_SET_TO_WRITE)
    BUSY_PIN_PROCESS_DONE;
}

void LCD_COMMAND_INPUT_NO_POLL(UINT8 COMMAND){

    LCD_RS_CONFIG(RS_SET_TO_COMMAND)
    LCD_RW_CONFIG(RW_SET_TO_WRITE)
    D0_D7_LINE_CLEAR;
    D0_D7_LINE_SET(COMMAND);
    ENABLE_LATCH_PULSE();
}

void LCD_COMMAND_INPUT(UINT8 COMMAND){

    LCD_READY_POLL();
    LCD_RS_CONFIG(RS_SET_TO_COMMAND)
    LCD_RW_CONFIG(RW_SET_TO_WRITE)
    D0_D7_LINE_CLEAR;
    D0_D7_LINE_SET(COMMAND);
    ENABLE_LATCH_PULSE();
}

void LCD_INSTRUCTION_STARTUP(void){
    
    LCD_DELAY_OPM_TIMER_INIT(300);
    while(!(TIM2_COMPLETE_EVENT)){}
    LCD_COMMAND_INPUT_NO_POLL(INIT_ROUTINE_CMD);
    LCD_DELAY_OPM_TIMER_UPDATE(100);
    while(!(TIM2_COMPLETE_EVENT)){}
    LCD_COMMAND_INPUT_NO_POLL(INIT_ROUTINE_CMD);
    LCD_DELAY_OPM_TIMER_UPDATE(10);
    while(!(TIM2_COMPLETE_EVENT)){}
    LCD_COMMAND_INPUT_NO_POLL(INIT_ROUTINE_CMD); 

    LCD_COMMAND_INPUT(INIT_2LINES_5X7_MATRIX);
    LCD_COMMAND_INPUT(SHIFT_CUR_RIGHT);
    LCD_COMMAND_INPUT(CLR_DSPL);
    LCD_COMMAND_INPUT(LCD_ON_CUR_ON);
}

void LCD_DATA_WRITE(UINT8 data){

    LCD_READY_POLL();
    LCD_RS_CONFIG(RS_SET_TO_DATA)
    LCD_RW_CONFIG(RW_SET_TO_WRITE)
    GPIOC->ODR = data;
    ENABLE_LATCH_PULSE();
}