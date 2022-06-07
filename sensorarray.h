#ifndef __SENSORARRAY_H__
#define __SENSORARRAY_H__

#include "mbed.h"

typedef struct {
    float floor;
    float track;
} Intensity;

typedef struct {
    float left;
    float center;
    float right;
} Values;

class SensorArray
{
public:
    SensorArray(
        const PinName& left_sensor,
        const PinName& center_sensor,
        const PinName& right_sensor
    ) :
        left_sensor{left_sensor},
        center_sensor{center_sensor},
        right_sensor{right_sensor},
        floorSet{false},
        trackSet{false}
    {}
    
    float getLeft();
    float getCenter();
    float getRight();

    void setFloor();
    void setTrack();

    Values getValues();
private:
    AnalogIn left_sensor;
    AnalogIn center_sensor;
    AnalogIn right_sensor;

    Intensity left_intensity;
    Intensity center_intensity;
    Intensity right_intensity;

    bool floorSet;
    bool trackSet;
};

#endif