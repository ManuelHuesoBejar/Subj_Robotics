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

#include "rotation_sensor.hpp"
#include "act_rotative_stepper.hpp"
#include <DRV8825.h>

Rotation_sensor rot_sens3 = Rotation_sensor(Q1_SENSOR);
DRV8825 stepper3 = DRV8825{STP_STEPS, STP3_DIR, STP3_STEP, STP_MODE0, STP_MODE1, STP_MODE2};
Rotative_actuator rot = Rotative_actuator(&rot_sens3, &stepper3, 0.0, 360.0);

void setup() {
  Serial.begin(115200);
  stepper3.begin(1., 32);
  // put your setup code here, to run once:
  rot.set_target(180.);
}

void loop() {
  // put your main code here, to run repeatedly:
  rot.move();
}
