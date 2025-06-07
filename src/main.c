/*
 * main.c - Debug Version
 */

#include "../Gpio/GPIO.h"
#include "../RCC/RCC.h"

#include "../Motor/motor.h"
#include "../ADC/ADC.h"

void setup(void);
void loop(void);
uint16 read_duty_percent();

int main(void)
{
    setup();

    while(1) {
        loop();
    }

    return 0;
}

void setup(void)
{
    ADC_INIT('B', 1, 1);
    const uint16 duty_cycle_percent =  read_duty_percent();
    Init_Motor(1, duty_cycle_percent);

}
void loop(void)
{

}

uint16 read_duty_percent()
{
    const uint16 digital_val = ADC_CONVERSION();
    const uint16 duty_cycle_percent = (uint16)((digital_val*100) / 4095.0);
    return  duty_cycle_percent;

}