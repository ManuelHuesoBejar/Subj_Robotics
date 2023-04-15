/*
Author: Echedey Luis Álvarez
Date: 2023-04-13
Subject: Robótica

File: program01.ino

Abstract: primer prototipo de software para probar cosiñas
*/

/* IntelliSense fix for VSCode, hardcoded, let it rest here for the team */
#include "Arduino.h"

/* Inclusión de cabeceras del programa */
#include "rotation_sensor.hpp"

/* Instrucciones para la manipulación directa de registros */
// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

/* Características modificables */
// Aumentar frecuencia de la señal de reloj del ADC
// [1] https://forum.arduino.cc/t/faster-analog-read/6604/6
#define FASTADC 1

/* Pines de los sensores */
#define SENS_Q1 A0

/* Estados disponibles del robot */
static enum State_machine {
    uninitialized_robot = 0,
    emergency_stop = 1,
    homing_required,
    swabbing_available,
    swabbing_procedure,
    swab_pick_up,
    swab_place,
} state;

static Rotation_sensor Q1_sens{SENS_Q1, 3600.0};

void setup() {
    state = uninitialized_robot;
    Q1_sens.begin();

#if FASTADC // [1], faster ADC
    // set prescale to 16
    sbi(ADCSRA,ADPS2);
    cbi(ADCSRA,ADPS1);
    cbi(ADCSRA,ADPS0);
#endif
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
    case swab_pick_up:
        break;
    case swab_place:
        break;

    default:
        // TODO: log & show error
        state = emergency_stop;
        break;
    }
}
