#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "mbed.h"

enum Direction {
    FORWARD = 0,
    BACKWARD = 1
};

class Motor
{
public:
    Motor(const PinName& power, const PinName& direction);
    void setValue(float value, Direction direction);
    void trigger();
private:
    PwmOut powerOut;
    DigitalOut directionOut;
    
    float motorValue;
    Direction motorDirection;
};

#endif