#include "encoder.h"

Encoder::Encoder(const PinName& pin) : inter{pin}, period{0}
{
    inter.rise([&]() {
        this->onRise();
    });

    inter.fall([&]() {
        this->onFall();
    });
}

unsigned int Encoder::getPeriod()
{
    return this->period;
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