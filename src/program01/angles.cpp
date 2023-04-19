#include "angles.hpp"

template <typename N> N deg2rad(N angle){
    return angle/180*PI;
}
template <typename N> N rad2deg(N angle){
    return angle/PI*180;
}