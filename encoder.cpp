#include "encoder.h"

unsigned int Encoder::getPeriod()
{
    return period;
}

void Encoder::onRise()
{
    timer.start();
}

void Encoder::onFall()
{
    timer.stop();
    period = chrono::duration_cast<chrono::milliseconds>(timer.elapsed_time()).count();
    timer.reset();
}