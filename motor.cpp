#include "motor.h"

Motor::Motor(const PinName& power, const PinName& direction) : power{power}, direction{direction} {};

void Motor::trigger()
{
    this->direction = 0;
    this->power = 0.3;
}