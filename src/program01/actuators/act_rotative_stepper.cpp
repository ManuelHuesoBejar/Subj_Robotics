#include "act_rotative_stepper.hpp"

Rotative_actuator::Rotative_actuator(Rotation_sensor* sens, DRV8825* driver) : sensor{sens}, stepper{stepper} {
}

Rotative_actuator::~Rotative_actuator() {
    stepper->disable();
}
