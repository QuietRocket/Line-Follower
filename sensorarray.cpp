#include "sensorarray.h"

SensorArray::SensorArray(const PinName& left, const PinName& center, const PinName& right) : left{left}, center{center}, right{right} {}

void SensorArray::debug()
{
    printf("L%d C%d R%d\n",
        (int)(left.read() * 100),
        (int)(center.read() * 100),
        (int)(right.read() * 100)
    );
}