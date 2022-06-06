#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "mbed.h"
#include "motor.h"
#include "encoder.h"
#include "sensorarray.h"

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
    );
    
    void init();
    void step();
private:
    Motor motor_left;
    Motor motor_right;

    Encoder encoder_left;
    Encoder encoder_right;

    SensorArray sensor_array;

    DigitalIn infra_forward;
    DigitalIn infra_right;
};

#endif