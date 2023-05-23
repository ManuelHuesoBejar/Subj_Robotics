#ifndef ROTATION_SENSOR_H
#define ROTATION_SENSOR_H

#include "resistive_sensor.hpp"

class Rotation_sensor : public Potentiometer_sensor {
private:
    double in_min = 0., in_max = 1023., out_min = 0., out_max = 3600./9.5; // Pote range entre rel transmisión

public:
    Rotation_sensor(uint8_t pin_)
        : Potentiometer_sensor{pin_} {};
    // Inicialización, por si fuese necesaria (lo será)
    void begin() {};
    // Getters & setters

    // Lectura del ángulo
    double read_angle();
};

#endif // ROTATION_SENSOR_H
