#include "actuator.hpp"

uint8_t Actuator::ID_counter = 0;

int Actuator::set_target(double target) {
    if (limits[0] <= target and target <= limits[1]) {
        target_pos = target;
        return 0;
    }
    else return -1;
}

void Actuator::set_limits(double lim1, double lim2) {
    if (lim1 < lim2) {
        limits[0] = lim1;
        limits[1] = lim2;
    }
    else {
        limits[0] = lim2;
        limits[1] = lim1;
    }
}
