#include "sensorarray.h"

int SensorArray::getLeft()
{
    return (int)(left_sensor.read() * 100);
}

int SensorArray::getCenter()
{
    return (int)(center_sensor.read() * 100);
}

int SensorArray::getRight()
{
    return (int)(right_sensor.read() * 100);
}

void SensorArray::setFloor()
{
    left_intensity.floor = getLeft();
    center_intensity.floor = getCenter();
    right_intensity.floor = getRight();
    floorSet = true;
}

void SensorArray::setTrack()
{
    left_intensity.track = getLeft();
    center_intensity.track = getCenter();
    right_intensity.track = getRight();
    trackSet = true;
}

Values SensorArray::getValues()
{
    return Values {
        (int)((getLeft() - left_intensity.track) * 100.0 / (left_intensity.floor - left_intensity.track)),
        (int)((getCenter() - center_intensity.track) * 100.0 / (center_intensity.floor - center_intensity.track)),
        (int)((getRight() - right_intensity.track) * 100.0 / (right_intensity.floor - right_intensity.track)),
    };
}

void SensorArray::debug()
{
    printf("L%d C%d R%d\n",
        getLeft(),
        getCenter(),
        getRight()
    );
}