//
// Created by DELL on 6/6/2025.
//

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H
#include "../LIB/Std_Types.h"

/* Timer 2 base address and registers */
#define TIM2_BASE       0x40000000
#define TIM2_CR1        REG32(TIM2_BASE + 0x00)
#define TIM2_CCMR1      REG32(TIM2_BASE + 0x18)
#define TIM2_CCER       REG32(TIM2_BASE + 0x20)
#define TIM2_CNT        REG32(TIM2_BASE + 0x24)
#define TIM2_PSC        REG32(TIM2_BASE + 0x28)
#define TIM2_ARR        REG32(TIM2_BASE + 0x2C)
#define TIM2_CCR1       REG32(TIM2_BASE + 0x34)
#define TIM2_CCR2       REG32(TIM2_BASE + 0x38)
#define TIM2_SR         REG32(TIM2_BASE + 0x10)

/* Input capture configuration */
#define IC1_SELECT_TI1  0x01    // CC1S = 01 in CCMR1 , input channel and connect it to TI1
#define IC1_RISING_EDGE 0x01    // CC1P = 0 in CCER , capture on rising edge

#endif //TIMER_PRIVATE_H
