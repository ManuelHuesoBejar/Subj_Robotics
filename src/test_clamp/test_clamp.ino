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

    #define SERVO_Q4 4
    #define CLAMP_OUT 5
#endif

#include <Servo.h>
#include "clamp.hpp"

Clamp Q4_clamp;

void setup() {
  Serial.begin(115200);

  Q4_clamp.attach(CLAMP_OUT);
}

void loop() {
  Q4_clamp.open();
  Q4_clamp.close();
}
