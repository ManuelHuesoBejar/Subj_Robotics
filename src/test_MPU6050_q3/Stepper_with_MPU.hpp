#pragma once

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include <DRV8825.h>
#include "actuator.hpp"

class Stepper_with_MPU_feedback : public Actuator {
    DRV8825* stepper;
    Adafruit_MPU6050* mpu6050;

    long last_operation = 0;
public:
    Stepper_with_MPU_feedback(DRV8825* stepper_, Adafruit_MPU6050* mpu6050_);
    Stepper_with_MPU_feedback(DRV8825* stepper_, Adafruit_MPU6050* mpu6050_, double lim1, double lim2);

    int move() override;
    void emergency_stop() override { stepper->disable(); }
    double get_current_pos() override;
};
