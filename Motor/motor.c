#include "motor.h"
#include <stdio.h>
#include "../RCC/RCC.h"
#include "../GPIO/Gpio.h"
#include "../PWM/PWM.h"


/*
 * channel 1 --> PA0
 * channel 2 --> PA1
 * channel 3 --> PB0
 * channel 4 --> PB1
 */
void Init_Motor(const uint8 channel, const uint16 duty_cycle_percent)
{
    PWM_Init(1);
    PWM_SetDutyCycle(duty_cycle_percent);
}

void Start_Motor()
{
    PWM_Start();
}

void Stop_Motor()
{
    PWM_Stop();
}

void Set_Motor_Speed(const uint16 duty_cycle_percent)
{
    PWM_SetDutyCycle(duty_cycle_percent);
}




