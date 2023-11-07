/*
 * lcd_engine.h
 *
 *  Created on: Nov 06, 2023
 *      Author: Thang Pham
 * 
 *  Header file that associates with lcd_engine.c
 */

void LCD_COMMAND_INPUT_NO_POLL(UINT8 COMMAND);
void LCD_COMMAND_INPUT(UINT8 COMMAND);
void ENABLE_LATCH_PULSE(void);
void LCD_INSTRUCTION_STARTUP(void);
void LCD_DATA_WRITE(UINT8 data);

/*
 *  Masks of BSRR GPIO Macros for LCD interface
 *  For LCD's pins of RS and RW
 *  
 *  Side note: This is also new type of if/else macro that
 *             I am playing around with.
 */

#define RS_SET              GPIOB_BSRR_SEL(PIN_5, BSRR_PIN_SET)
#define RS_CLEAR            GPIOB_BSRR_SEL(PIN_5, BSRR_PIN_CLEAR)
#define RW_SET              GPIOB_BSRR_SEL(PIN_6, BSRR_PIN_SET)
#define RW_CLEAR            GPIOB_BSRR_SEL(PIN_6, BSRR_PIN_CLEAR)
#define ENABLE_SET          GPIOB_BSRR_SEL(PIN_7, BSRR_PIN_SET)
#define ENABLE_CLEAR        GPIOB_BSRR_SEL(PIN_7, BSRR_PIN_CLEAR)

#define BUSY_PIN_PROCESS_READ         GPIOC->MODER &= ~(0xFFFF)
#define BUSY_PIN_PROCESS_DONE         GPIOC->MODER |= 0x5555

#define RS_SET_TO_COMMAND   0
#define RS_SET_TO_DATA      1
#define RW_SET_TO_WRITE     0
#define RW_SET_TO_READ      1

#define LCD_RS_CONFIG(RS_CONFIG_OPTION) if(RS_CONFIG_OPTION == RS_SET_TO_DATA){RS_SET;} else if(RS_CONFIG_OPTION == RS_SET_TO_COMMAND){RS_CLEAR;} else{/*TODO Implement Error Handling*/}
#define LCD_RW_CONFIG(RW_CONFIG_OPTION) if(RW_CONFIG_OPTION == RW_SET_TO_READ){RW_SET;} else if(RW_CONFIG_OPTION == RW_SET_TO_WRITE){RW_CLEAR;} else{/*TODO Implement Error Handling*/}

/*
 *  Macros for LCD's data lines D0 - D7
 */

#define D0_D7_LINE_SET(COMMAND) SET_BIT(GPIOC->BSRR, COMMAND << BSRR_PIN_SET)
#define D0_D7_LINE_CLEAR        SET_BIT(GPIOC->BSRR, 0xFF << BSRR_PIN_CLEAR)

/*
 *  List of commands for the LCD
 */

#define INIT_ROUTINE_CMD            0x30
#define LCD_ON_CUR_ON               0x0F
#define CLR_DSPL                    0x01
#define RETURN_HOME                 0x02
#define SHIFT_CUR_LEFT              0x04
#define SHIFT_CUR_RIGHT             0X06
#define SHIFT_DSPL_RIGHT            0x05
#define SHIFT_DSPL_LEFT             0x07
#define DSPL_ON_CUR_BLINK           0x0E
#define FORCE_CUR_FIRST_LINE        0x80
#define FORCE_CUR_SECOND_LINE       0xC0
#define INIT_2LINES_5X7_MATRIX      0x38
#define CUR_FIRST_LINE_POS_3        0x83
#define ACTIVATE_SECOND_LINE        0x3C
#define DSPL_OFF_CUR_OFF            0x08
#define JMP_2ND_LINE_POS_1          0xC1
#define DSPL_ON_CUR_ON              0x0C
#define JMP_2ND_LINE_POS_1          0xC1
#define JMP_2ND_LINE_POS_2          0xC2