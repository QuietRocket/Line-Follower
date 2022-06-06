#include "mbed.h"

#include "robot.h"

Robot robot(
    // Motors
    P2_4, P2_5, // Left and right power
    P2_2, P0_6, // Left and right direction

    // Encoders
    P0_4, P0_5, // Left and right

    // Photoresistor array
    P0_24, P0_25, P0_26, // L C R

    // Infrared
    P0_0, P0_1 // Forward and right
);

int main()
{
    robot.init();
    
    while (true)
    {
        robot.step();
    }
}