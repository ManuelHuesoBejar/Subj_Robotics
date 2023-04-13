/*
Author: Echedey Luis Álvarez
Date: 2023-04-13
Subject: Robótica

File: program01.ino

Abstract: primer prototipo de software para probar cosiñas
*/

// Inclusión de cabeceras del programa
#include "rotation_sensor.hpp"

// Pines de los sensores
#define SENS_Q1 A0

void setup() {
    Rotation_sensor Q1_sens{SENS_Q1, 3600.0};
}

void loop() {

}
