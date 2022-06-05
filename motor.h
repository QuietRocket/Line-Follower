#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "mbed.h"

class Motor
{
public:
    Motor(const PinName& power, const PinName& direction);
    void trigger();
private:
    PwmOut power;
    DigitalOut direction;
    bool forward;
};

#endif