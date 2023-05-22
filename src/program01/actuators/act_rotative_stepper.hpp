#pragma once

#include <DRV8825.h>

#include "actuators/actuator.hpp"
#include "sensors/rotation_sensor.hpp"

class Rotative_actuator: virtual public Actuator {
    Rotation_sensor* sensor;
    DRV8825* stepper;

public:
    Rotative_actuator(Rotation_sensor* sens, DRV8825* driver);
    ~Rotative_actuator();

    int move() override;
    void emergency_stop() override;
    double get_current_pos() override;
};
