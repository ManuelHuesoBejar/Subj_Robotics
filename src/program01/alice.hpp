#pragma once

/* Includes */
// Sensores
#include "act_rotative_stepper.hpp"

/* Definiciones entorno */
// Pines y plataforma-específico
#ifdef ARDUINO_AVR_MEGA2560
    #define Q1_SENSOR A1
    #define Q2_SENSOR A2
    #define Q4_SENSOR A4
    #define Q5_SENSOR A5
    #define CLAMP_SENSOR A8

#endif

class Alice {
    // Actuadores
    Rotative_actuator q1{};

};
