#include "rotation_sensor.hpp"

static double mapd(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double Rotation_sensor::read_angle() {
    /* Return value in degrees */
    int reading = read();
    double angle = mapd(reading, in_min, in_max, out_min, out_max);
    return angle;
}
