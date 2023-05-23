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
#include "sensors/rotation_sensor.hpp"

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

/* Definiciones entorno */
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
static DRV8825 stepper3 {STP_STEPS, STP3_DIR, STP3_STEP, STP_MODE0, STP_MODE1, STP_MODE2};
void setup() {
    state = uninitialized_robot;
    Q1_sens.begin();

#if FASTADC // [1], faster ADC
    // set prescale to 16
    sbi(ADCSRA,ADPS2);
    cbi(ADCSRA,ADPS1);
    cbi(ADCSRA,ADPS0);
#endif

    // Tontería varia
    Serial.begin(115200);
    Serial.println(">> Webo!");
    Serial.println("Sys: Modelo M ha despertado");
    Serial.println(">> Hola, me dispongo a meterte un hisopo por la nariz.");
    Serial.println("Sys: Modelo M te está amenazando, hazle caso.");
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
