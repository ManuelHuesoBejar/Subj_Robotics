#ifndef POTENTIOMETER_SENSOR_H
#define POTENTIOMETER_SENSOR_H

#include <stdint.h>
#include "Arduino.h"

// ADC de 10 bits de resolución
constexpr int MAX_ADC = 1023;

class Potentiometer_sensor {
protected:
    const uint8_t pin;
    bool reverse = false;

public:
    Potentiometer_sensor(uint8_t pin_)
        : pin{pin_} {};
    
    // Getters & setters
    bool is_reversed() { return reverse; }
    void set_reversed(bool reversed_) { reverse = reversed_; }
    // Lectura
    int read() { // TODO: acelerar con lectura directa por registros (?)
        return reverse ? (MAX_ADC - analogRead(pin)) : analogRead(pin);
    }
};

#endif // POTENTIOMETER_SENSOR_H
