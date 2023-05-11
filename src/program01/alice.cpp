#include "alice.hpp"

int Alice::watchdog()
{
    int error = 0;
    error += q1.watchdog();
    error += q2.watchdog();
    error += q3.watchdog();
    error += q4.watchdog();
    // error += q_effector.watchdog();
    return error;
}

int Alice::move()
{
    int error = 0;
    error += q1.move();
    error += q2.move();
    error += q3.move();
    error += q4.move();
    // error += q_effector.move();
    return error;
}