#ifndef MOTOR_H
#define MOTOR_H

#include "../LIB/STD_TYPES.h"

void Init_Motor(const uint8 channel, const uint16 duty_percent);
void Start_Motor();
void Stop_Motor();
void Set_Motor_Speed(const uint16 speed);

#endif //MOTOR_H
