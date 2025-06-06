//
// Created by dell on 6/4/2025.
//

#ifndef ADC_H
#define ADC_H
#include "../LIB/Std_Types.h"

#define ADC_IN0   0
#define ADC_IN1   1
#define ADC_IN2   2
#define ADC_IN3   3
#define ADC_IN4   4




void ADC_INIT(uint8 PORT , uint8 PIN , uint8 CHANNEL);
uint16 ADC_CONVERSION() ;

#endif //ADC_H
