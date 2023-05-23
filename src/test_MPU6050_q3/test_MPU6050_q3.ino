// Pines y plataforma-específico
#ifdef ARDUINO_AVR_MEGA2560
    #define Q1_SENSOR A1
    #define Q2_SENSOR A2
    #define Q4_SENSOR A4
    #define Q5_SENSOR A5
    #define CLAMP_SENSOR A8
    #define STP_STEPS short(360/1.8)
    #define STP_MODE0 27
    #define STP_MODE1 29
    #define STP_MODE2 31
    #define STP1_STEP 23
    #define STP1_DIR 25
    #define STP2_STEP 37
    #define STP2_DIR 39
    #define STP3_STEP 51
    #define STP3_DIR 53
#endif

#include "Stepper_with_MPU.hpp"
#include <DRV8825.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;
DRV8825 stepper1 = DRV8825{STP_STEPS, STP1_DIR, STP1_STEP, STP_MODE0, STP_MODE1, STP_MODE2};
Stepper_with_MPU_feedback rot = Stepper_with_MPU_feedback(&stepper1, &mpu, -180.0, 180.0);

void setup() {
  Serial.begin(115200);
  stepper1.begin(1., 32);
  mpu.begin();
  rot.set_target(0.);
}

void loop() {
  rot.move();
}
