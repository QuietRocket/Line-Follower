#ifndef __SENSORARRAY_H__
#define __SENSORARRAY_H__

#include "mbed.h"

class SensorArray
{
public:
    SensorArray(const PinName& left, const PinName& center, const PinName& right);
    void debug();
private:
    AnalogIn left;
    AnalogIn center;
    AnalogIn right;
};

#endif