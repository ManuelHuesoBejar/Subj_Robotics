#ifndef ROTATION_SENSOR_H
#define ROTATION_SENSOR_H

#include "resistive_sensor.hpp"

class Rotation_sensor : public Potentiometer_sensor {
private:
    double i_rel = 1.0; // Relación de transmisión
    double offset = 0.0; // En donde ubicamos el cero

public:
    Rotation_sensor(uint8_t pin_, double spin_range_)
        : Potentiometer_sensor{pin_, spin_range_} {};
    Rotation_sensor(uint8_t pin_, double spin_range_, double i_rel_)
        : Potentiometer_sensor{pin_, spin_range_}, i_rel{i_rel_} {};
    
    double read_angle();
    double get_offset() { return offset; }
    void set_offset(double offset_) { offset = offset_; }
};

#endif // ROTATION_SENSOR_H
