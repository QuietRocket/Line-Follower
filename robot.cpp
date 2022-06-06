#include "robot.h"

Robot::Robot(
    // Motor power
    const PinName& motor_left_power,
    const PinName& motor_right_power,

    // Motor direction
    const PinName& motor_left_direction,
    const PinName& motor_right_direction,    

    // Encoders
    const PinName& encoder_left,
    const PinName& encoder_right,

    // Photoresistor array
    const PinName& phr_left,
    const PinName& phr_center,
    const PinName& phr_right,

    // Infrared
    const PinName& infra_forward,
    const PinName& infra_right
) :
    motor_left{motor_left_power, motor_left_direction},
    motor_right{motor_right_power, motor_right_direction},
    encoder_left{encoder_left},
    encoder_right{encoder_right},
    sensor_array{phr_left, phr_center, phr_right},
    infra_forward{infra_forward},
    infra_right{infra_right}
{};

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