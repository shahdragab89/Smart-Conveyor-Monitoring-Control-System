

#include <stdint.h>

#include "../Lib/Std_Types.h"

#include <stdio.h>

#include "../RCC/RCC.h"
//#include "../segment/segm.h"
#include "../Gpio/GPIO.h"
//#include "../EXTI/EXTI.h"
#include"../ADC/ADC.h"
#include"../PWM/PWM.h"
#include "../Motor/motor.h"

#define POT_PORT    GPIO_A
#define POT_PIN     1
#define POT_CHANNEL 1

#define THRESHOLD   2048git

void setup(void);
void loop(void);
uint16 read_duty_cycle(void);

int main()
{
    setup();

    while (1)
    {
        loop();
    }

    // This line should never be reached
    return 0;
}

void setup(void)
{
    Rcc_Init();

    Rcc_Enable(RCC_GPIOA);
    Rcc_Enable(RCC_GPIOB);

    Init_Motor(1, 50);

    Rcc_Enable(RCC_SYSCFG);

    ADC_INIT(POT_PORT, POT_PIN, POT_CHANNEL);
    Gpio_Init(GPIO_B, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_Init(GPIO_B, 1, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_Init(GPIO_A, 3, GPIO_INPUT, GPIO_PULL_UP);
    Gpio_Init(GPIO_A, 7, GPIO_OUTPUT, GPIO_PUSH_PULL);
}

void loop(void)
{
    uint16 duty_cycle_percent = read_duty_cycle();  // Read duty cycle from ADC

    Gpio_WritePin(GPIO_A, 7, HIGH);

    Set_Motor_Speed(duty_cycle_percent);
    Gpio_WritePin(GPIO_B, 0, HIGH);
    Gpio_WritePin(GPIO_B, 1, LOW);
    if (Gpio_ReadPin(GPIO_A, 3)==1) {
        Gpio_WritePin(GPIO_A, 7, HIGH);
    }else {
        Gpio_WritePin(GPIO_A, 7, LOW);
    }


    for (volatile int i = 0; i < 100000; i++);
}

uint16 read_duty_cycle(void)
{
    uint16 digital_value = ADC_CONVERSION();  // Read ADC value
    uint16 duty_cycle_percent = (digital_value * 100) / 4095; //
    return duty_cycle_percent;  // Convert to percentage (0-100%)
}
