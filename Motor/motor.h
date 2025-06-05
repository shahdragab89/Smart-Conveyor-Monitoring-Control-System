#ifndef MOTOR_H
#define MOTOR_H

#include "../LIB/STD_TYPES.h"

#define MOTOR_PIN 5

void Init_Motor(uint8 motor_pin, char motor_gpio_peripheral);
void Start_Motor(void);
void Stop_Motor(void);
void Set_Motor_Speed(uint8 duty_cycle);


#endif //MOTOR_H
