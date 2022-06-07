#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "mbed.h"
#include <chrono>

#include "motor.h"
#include "encoder.h"
#include "sensorarray.h"

enum State
{
    INIT,
    GET_FLOOR,
    GET_FLOOR_DONE,
    GET_TRACK,
    GET_TRACK_DONE,
    GO,
    STOP
};

class Robot
{
public:
    Robot(
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
        state{State::INIT},
        motor_left{motor_left_power, motor_left_direction},
        motor_right{motor_right_power, motor_right_direction},
        encoder_left{encoder_left},
        encoder_right{encoder_right},
        sensor_array{phr_left, phr_center, phr_right},
        infra_forward{infra_forward},
        infra_right{infra_right},
        currentValues{0, 0, 0}
    {}

    void debug();
    
    void init();
    void step();
private:
    // Peripherals
    State state;

    Motor motor_left;
    Motor motor_right;

    Encoder encoder_left;
    Encoder encoder_right;

    SensorArray sensor_array;

    DigitalIn infra_forward;
    DigitalIn infra_right;

    // Non-peripherals
    Ticker ticker;
    bool debugSwitch;
    Values currentValues;

    // Internal methods
    void reaction();
};

#endif