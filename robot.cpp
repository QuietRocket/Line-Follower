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
    if (state == State::GO)
    {
        printf("%d %d\n", -currentValues.left + currentValues.right, currentValues.center);
    }
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
            currentValues = sensor_array.getValues();
            reaction();
            break;
        case STOP:
            break;
    }

    motor_left.trigger();
    motor_right.trigger();
}

void Robot::reaction()
{
    if (currentValues.center > 25)
    {
        motor_left.setValue(0, Direction::FORWARD);
        motor_right.setValue(0, Direction::FORWARD);
        state = State::STOP;
        return;
    }

    motor_left.setValue(0.3, Direction::FORWARD);
    motor_right.setValue(0.3, Direction::FORWARD);
}