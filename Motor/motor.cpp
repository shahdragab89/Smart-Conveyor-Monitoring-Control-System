#include "motor.h"

#include <stdio.h>

#include "../RCC/RCC.h"
#include "../GPIO/Gpio.h"

static uint8 MOTOR_PIN_NUM;
static char MOTOR_GPIO_PORT;

/*
 * Motor Pins from 0 to 15
 * motor_gpio_peripheral: 'A', 'B', 'C', 'D', 'E', 'H'
 */
void Init_Motor(const uint8 motor_pin,const char motor_gpio_peripheral)
{
    MOTOR_PIN_NUM = motor_pin;
    MOTOR_GPIO_PORT = motor_gpio_peripheral;

    Rcc_Init();

    //Enable GPIO peripheral for motor control from RCC
    switch (motor_gpio_peripheral)
    {
        case 'A':
            Rcc_Enable(RCC_GPIOA);
            break;
        case 'B':
            Rcc_Enable(RCC_GPIOB);
            break;
        case 'C':
            Rcc_Enable(RCC_GPIOC);
            break;
        case 'D':
            Rcc_Enable(RCC_GPIOD);
            break;
        case 'E':
            Rcc_Enable(RCC_GPIOE);
            break;
        case 'H':
            Rcc_Enable(RCC_GPIOH);
            break;
        default:
            printf("Invalid GPIO peripheral: %c\n", motor_gpio_peripheral);
            return;
    }

    Gpio_Init(motor_gpio_peripheral, motor_pin, GPIO_AF, GPIO_PUSH_PULL);
}


