#ifndef __SENSORARRAY_H__
#define __SENSORARRAY_H__

#include "mbed.h"

typedef struct {
    int floor;
    int track;
} Intensity;

typedef struct {
    int left;
    int center;
    int right;
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
    
    int getLeft();
    int getCenter();
    int getRight();

    void setFloor();
    void setTrack();

    Values getValues();

    void debug();
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