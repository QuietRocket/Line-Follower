#include "robot.h"

void Robot::init()
{
    motor_left.setValue(0.6, Direction::FORWARD);
    motor_right.setValue(0.6, Direction::FORWARD);
}

void Robot::step()
{
    motor_left.trigger();
    motor_right.trigger();
}