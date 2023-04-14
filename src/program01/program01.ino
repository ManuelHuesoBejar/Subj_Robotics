/*
Author: Echedey Luis Álvarez
Date: 2023-04-13
Subject: Robótica

File: program01.ino

Abstract: primer prototipo de software para probar cosiñas
*/

// Lo siento, uso VSCode
#include "Arduino.h"

// Inclusión de cabeceras del programa
#include "rotation_sensor.hpp"

// Pines de los sensores
#define SENS_Q1 A0

// Estados disponibles del robot
enum State_machine {
    uninitialized_robot = 0,
    emergency_stop = 1,
    homing_required,
    swabbing_available,
    swabbing_procedure,
    swab_change_required,
} state;

Rotation_sensor Q1_sens{SENS_Q1, 3600.0};

void setup() {
    state = uninitialized_robot;
    Q1_sens.begin();
}

void loop() {
    switch (state)
    {
    case uninitialized_robot:
        break;
    case emergency_stop:
        break;
    case homing_required:
        break;
    case swabbing_available:
        break;
    case swabbing_procedure:
        break;
    case swab_change_required:
        break;

    default:
        // TODO: log & show error
        state = emergency_stop;
        break;
    }
}
