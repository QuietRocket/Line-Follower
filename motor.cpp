#include "motor.h"

void Motor::setValue(float value, Direction direction)
{
    motorValue = value;
    motorDirection = direction;
}

void Motor::trigger()
{
    powerOut = motorValue;
    directionOut = motorDirection;
}