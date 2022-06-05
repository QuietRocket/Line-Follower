#include "mbed.h"
#include <chrono>
#include <limits.h>

#include "encoder.h"
#include "motor.h"

// -- Declaring peripherals --
// -> Motors
Motor mot_left(P2_5, P2_3);
Motor mot_right(P2_4, P2_2);

// -> Encoder
Encoder enc_left(P0_4);
Encoder enc_right(P0_5);

// -> Photoresistances
// AnalogIn ph_left(P0_23);
AnalogIn ph_left_center(P0_24);
AnalogIn ph_center(P0_25);
AnalogIn ph_right_center(P0_26);
// AnalogIn ph_right(P1_30);

// -> Infrared
DigitalIn cg(P0_0);
DigitalIn cd(P0_1);

void reaction()
{
    
}

int main()
{
    while (true)
    {
        for (unsigned int i = 0; i < 10; ++i)
            wait_ns(INT_MAX);

        // -- READ INFRA CAPTEURS --
        // printf("%d %d\n",
        //     cd.read(), cg.read()
        // );

        // -- FAILED TEST : SET DIRECTION --
        // m1 = 0;
        // m2 = 1;

        // printf("%d %d\n", enc_left.getPeriod(), enc_right.getPeriod());

        printf("%d %d %d\n",
            (int)(ph_left_center.read() * 100),
            (int)(ph_center.read() * 100),
            (int)(ph_right_center.read() * 100)
        );
    }
}