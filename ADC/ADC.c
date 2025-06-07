
#include "../LIB/Std_Types.h"
#include "../GPIO/GPIO.h"
#include "ADC.h"
#include"ADC_Private.h"
#include "../RCC/RCC.h"

void ADC_INIT(uint8 PORT , uint8 PIN , uint8 CHANNEL) {
    Gpio_Init(PORT, PIN , GPIO_ANALOG , GPIO_NO_PULL_DOWN);

     Rcc_Enable(RCC_ADC1);  // Make sure this sets bit 8 in RCC->APB2ENR
    ADC_COMMON->CCR &= ~(0x3 << 16);  // Clear prescaler bits
    ADC_COMMON->CCR |=  (0x0 << 16);  // Set to ÷2 (fastest)



    ADC1->CR1 = 0;
    ADC1->CR2 = 0;
    ADC1->CR2 |= (1 << 0);   // ADON


    ADC1->CR2 &= ~(1 << 1);   // Single conversion mode
    ADC1->CR2 |= (1 << 10);   // EOCS


    if (CHANNEL <= 9) {
        ADC1->SMPR2 &= ~(0x7 << (CHANNEL * 3));
        ADC1->SMPR2 |=  (0x7 << (CHANNEL * 3)); // 480 cycles

    } else {
        ADC1->SMPR1 &= ~(0x7 << ((CHANNEL - 10) * 3));
        ADC1->SMPR1 |=  (0x4 << ((CHANNEL - 10) * 3));
    }

    ADC1->SQR1 &= ~(0xF << 20);
    ADC1->SQR3 &= ~0x1F;
    ADC1->SQR3 |= CHANNEL;
}

uint16 ADC_CONVERSION() {

    ADC1->CR2 |= (1 << 30);            // SWSTART = 1 to begin conversion

    while (!(ADC1->SR & (1 << 1)));    // Wait until conversion completes

    return ADC1->DR;                   // Read result and automatically clear EOC
}

