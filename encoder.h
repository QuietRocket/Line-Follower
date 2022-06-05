#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "mbed.h"

class Encoder
{
public:
    Encoder(const PinName& pin);
    unsigned int getPeriod();
private:
    void onRise();
    void onFall();
    InterruptIn inter;
    Timer timer;
    unsigned int period;
};

#endif