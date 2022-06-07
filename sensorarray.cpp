#include "sensorarray.h"

void SensorArray::setFloor()
{
    left_intensity.floor = left_sensor.read() * 100;
    center_intensity.floor = center_sensor.read() * 100;
    right_intensity.floor = right_sensor.read() * 100;
}

void SensorArray::setTrack()
{
    left_intensity.track = left_sensor.read() * 100;
    center_intensity.track = center_sensor.read() * 100;
    right_intensity.track = right_sensor.read() * 100;
}

void SensorArray::debug()
{
    printf("L%d C%d R%d\n",
        (int)(left_sensor.read() * 100),
        (int)(center_sensor.read() * 100),
        (int)(right_sensor.read() * 100)
    );
}