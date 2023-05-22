#pragma once

#include <DRV8825.h>

#include "actuator.hpp"
#include "rotation_sensor.hpp"

class Rotative_actuator: virtual public Actuator {
    Rotation_sensor* sensor;
    DRV8825* stepper;

    long last_operation = 0;

public:
    Rotative_actuator(Rotation_sensor* sensor_, DRV8825* stepp);
    Rotative_actuator(Rotation_sensor* sensor_, DRV8825* stepp, double lim1, double lim2);

    int move() override;
    void emergency_stop() override {};
    double get_current_pos() override;
};
