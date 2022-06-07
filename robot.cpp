#include "robot.h"

void Robot::init()
{
    // Trigger debug every half a second.
    ticker.attach([&]() {
        debugSwitch = true;
    }, std::chrono::milliseconds(500));
}

void Robot::debug()
{
    // sensor_array.debug();
    // printf("%d\n", infra_right.read());
}

void Robot::step()
{
    // If debug is triggered, run debug 
    if (debugSwitch)
    {
        debug();
        debugSwitch = false;
    }

    switch (state)
    {
        case INIT:
            state = State::GET_FLOOR;
            break;
        case GET_FLOOR:
            if (!infra_right.read()) // If infra right blocked
            {
                sensor_array.setFloor();
                state = State::GET_FLOOR_DONE;
            }
            break;
        case GET_FLOOR_DONE:
            if (infra_right.read()) state = State::GET_TRACK;
            break;
        case GET_TRACK:
            if (!infra_right.read()) // If infra right blocked
            {
                sensor_array.setTrack();
                state = State::GET_TRACK_DONE;
            }
            break;
        case GET_TRACK_DONE:
            if (infra_right.read()) state = State::GO;
            break;
        case GO:
            printf("%d\n", abs(-5 - 10));
            state = State::STOP;
            break;
        case STOP:
            break;
    }
    
    motor_left.trigger();
    motor_right.trigger();
}

void Robot::reaction()
{

}