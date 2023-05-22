#pragma once

#include <DRV8825.h>

#include "actuator.hpp"
#include "sensors/rotation_sensor.hpp"

class Rotative_actuator: virtual public Actuator {
    Rotation_sensor* sensor;
    DRV8825* stepper;

public:
    Rotative_actuator(Rotation_sensor* sensor_, DRV8825* stepp);

    int move() override;
    void emergency_stop() override;
    double get_current_pos() override;
};
