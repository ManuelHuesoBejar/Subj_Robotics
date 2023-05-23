#pragma once

#include <Servo.h>

class Clamp: public Servo {
    bool opened = false;
public:
    void open();
    void close();
    void toggle();
    void attach(uint8_t pin) { Servo::attach(pin); open(); }
    void deattach() { open(); Servo::detach(); }
};
