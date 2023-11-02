/*
 * timer_init.h
 *
 *  Created on: Nov 01, 2023
 *      Author: Thang Pham
 */

/*
 *  Macro for TIMERx Enable Initialization
 */

/*
 *  Macro for Timer Enables
 */

/* For APB1ENR Timers */
#define TIMER_2_EN  (1U << 0)
#define TIMER_3_EN  (1U << 1)
#define TIMER_4_EN  (1U << 2)
#define TIMER_5_EN  (1U << 3)
#define TIMER_6_EN  (1U << 4)
#define TIMER_7_EN  (1U << 5)
#define TIMER_12_EN (1U << 6)
#define TIMER_13_EN (1U << 7)
#define TIMER_14_EN (1U << 8)

/*
 *  APB1ENR Timers
 *  TIM2, TIM3, TIM4, TIM5, TIM6,
 *  TIM7, TIM12, TIM13, TIM14
 */

#define APB1_TIMERx_ENABLE(TIMER_x_EN)         SET_BIT(RCC->APB1ENR, TIMER_x_EN)

/*
 *  APB2ENR Timers
 */