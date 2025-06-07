//
// Created by DELL on 6/5/2025.
//
#include "Timer.h"
#include "Timer_Private.h"
#include "../RCC/RCC.h"
#include "../GPIO/GPIO.h"
#include <../LIB/Std_Types.h>
#include "../LIB/Utils.h"
#include "../LIB/Bit_Operations.h"

static uint32 last_capture = 0;
static float calibration_factor = 0.2f; // 0.2m per pulse (adjust based on your system)

void TIM_Init(uint8 channel)
{
    /* 1. Enable timer clock */
    Rcc_Enable(RCC_TIM2);

    /* 2. Configure GPIO for timer input */
    Gpio_Init(GPIO_A, 0, GPIO_AF, GPIO_NO_PULL_DOWN); // PA0 as AF for TIM2_CH1

    /* 3. Configure timer base */
    TIM2_CR1 = 0x00;       // Disable timer
    TIM2_PSC = 79;         // 80MHz/80 = 1MHz (1µs resolution)
    TIM2_ARR = 0xFFFFFFFF; // Maximum count value (32 bit)

    /* 4. Configure input capture */
    if(channel == TIM_CH1) {
        TIM2_CCMR1 &= ~(0x03 << 0);   // Clear CC1S bits
        TIM2_CCMR1 |= IC1_SELECT_TI1; // CC1 as input, IC1 mapped to TI1
        TIM2_CCER |= IC1_RISING_EDGE;        // Capture on rising edge
    }

    /* 5. Enable timer */
    TIM2_CR1 |= (1 << 0);  // Counter enable
}

uint32 TIM_GetCaptureValue(void)
{
    if(TIM2_SR & (1 << 1)) // Check capture flag for channel 1
    {
        uint32 current_capture = TIM2_CCR1;
        uint32 pulse_width = current_capture - last_capture;
        last_capture = current_capture;
        TIM2_SR &= ~(1 << 1); // Clear flag
        return pulse_width;    // Returns microseconds
    }
    return 0;
}

float TIM_GetSpeed(void)
{
    uint32 pulse_width = TIM_GetCaptureValue();
    if(pulse_width == 0) return 0.0f;

    // Calculate speed: (distance per pulse) / (time per pulse)
    return calibration_factor / (pulse_width * 1e-6f); // m/s
}