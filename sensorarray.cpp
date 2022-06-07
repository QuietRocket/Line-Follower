#include "sensorarray.h"

float SensorArray::getLeft()
{
    return left_sensor.read();
}

float SensorArray::getCenter()
{
    return center_sensor.read();
}

float SensorArray::getRight()
{
    return right_sensor.read();
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
        (getLeft() - left_intensity.track) / (left_intensity.floor - left_intensity.track),
        (getCenter() - center_intensity.track) / (center_intensity.floor - center_intensity.track),
        (getRight() - right_intensity.track) / (right_intensity.floor - right_intensity.track),
    };
}