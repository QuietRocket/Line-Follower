#include "motor.h"

Motor::Motor(const PinName& powerOut, const PinName& directionOut) : powerOut{powerOut}, directionOut{directionOut} {};

void Motor::setValue(float value, Direction direction)
{
    this->motorValue = value;
    this->motorDirection = direction;
}

void Motor::trigger()
{
    this->powerOut = this->motorValue;
    this->directionOut = this->motorDirection;
}