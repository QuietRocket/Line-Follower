#include "sensorarray.h"

void SensorArray::debug()
{
    printf("L%d C%d R%d\n",
        (int)(left.read() * 100),
        (int)(center.read() * 100),
        (int)(right.read() * 100)
    );
}