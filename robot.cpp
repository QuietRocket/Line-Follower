#include "robot.h"

const int FREQUENCY = 100;

void Robot::init()
{
    // Trigger debug every half a second.
    debugTicker.attach([&]() {
        debugSwitch = true;
    }, std::chrono::milliseconds(500));

    // Compute reaction
    reactionTicker.attach([&]() {
        reactionSwitch = true;
    }, std::chrono::milliseconds(1000 / FREQUENCY));
}

float error_current = 0;
float error_sum = 0;
float error_prev = 0;
float error_diff = 0;

void Robot::debug()
{
    if (state == State::GO)
    {
        printf("%d %d %d\n", (int)(error_current * 100), (int)(error_sum * 100), (int)(currentValues.center * 100));
    }
}

void Robot::step()
{
    // If debug is triggered, run it
    if (debugSwitch)
    {
        debug();
        debugSwitch = false;
    }

    if (state == State::GO || state == State::LOST)
    {
        currentValues = sensor_array.getValues();
    }

    switch (state)
    {
        case INIT:
            state = State::GET_FLOOR;
            break;
        case GET_FLOOR:
            if (!infra_forward.read()) // If infra right blocked
            {
                sensor_array.setFloor();
                state = State::GET_FLOOR_DONE;
            }
            break;
        case GET_FLOOR_DONE:
            if (infra_forward.read()) state = State::GET_TRACK;
            break;
        case GET_TRACK:
            if (!infra_forward.read()) // If infra right blocked
            {
                sensor_array.setTrack();
                state = State::GET_TRACK_DONE;
            }
            break;
        case GET_TRACK_DONE:
            if (infra_forward.read()) state = State::GO;
            break;
        case GO:
        case LOST:
            if (reactionSwitch)
            {
                reaction();
                reactionSwitch = false;
            }
            break;
        case STOP:
            // if (!infra_forward.read()) // If infra right blocked
            // {
            //     state = State::GO;
            // }
            printf("STOPPED!\n");
            break;
    }

    motor_left.trigger();
    motor_right.trigger();
}


void Robot::reaction()
{
    if (state == State::GO && currentValues.center > 0.90)
    {
        state = State::LOST;
        lostTimer.reset();
        lostTimer.start();
        return;
    }

    if (state == State::LOST)
    {
        if (currentValues.center <= 0.90)
        {
            state = State::GO;
            lostTimer.stop();
        }
        else if (chrono::duration_cast<chrono::seconds>(lostTimer.elapsed_time()).count() > 1)
        {
            printf("LOST!\n");

            state = State::STOP;
            lostTimer.stop();
            motor_left.setValue(0, Direction::FORWARD);
            motor_right.setValue(0, Direction::FORWARD);

            return;
        }
    }

    error_current = (currentValues.left > currentValues.right) ? -currentValues.left : currentValues.right;
    // error_current *= 1 + currentValues.right;

    error_sum += error_current / FREQUENCY;
    if (error_sum > 1) error_sum = 1;
    if (error_sum < -1) error_sum = -1;

    error_diff = error_current - error_prev;
    error_prev = error_current;

    const float kc = 0.75;
    const float ks = 1;
    const float kd = 2;

    float total = kc * error_current + ks * error_sum + kd * error_diff;

    const float forwardSpeed = 0.27;

    float leftValue = forwardSpeed - total;
    float rightValue = forwardSpeed + total;

    motor_left.setValue(leftValue, Direction::FORWARD);
    motor_right.setValue(rightValue, Direction::FORWARD);
}