#include "rotation_sensor.hpp"

double Rotation_sensor::read_angle() {
    /* Return value in degrees */
    int reading = read();
    double angle = reading * spin_range / ( i_rel * 1023 );
    return angle - offset;
}
