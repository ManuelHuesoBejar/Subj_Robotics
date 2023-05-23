#include "clamp.hpp"

void Clamp::open() {
    opened = false;
    writeMicroseconds(900);
    delay(200);
}

void Clamp::close() {
    opened = true;
    writeMicroseconds(2100);
    delay(200);
}

void Clamp::toggle() {
    if (opened) close();
    else open();
}
