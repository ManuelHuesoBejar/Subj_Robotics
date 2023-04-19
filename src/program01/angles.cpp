#include "angles.hpp"
#include <math.h>

template <typename N> inline N deg2rad(N angle){
    return angle/180*PI;
}
template <typename N> inline N rad2deg(N angle){
    return angle/PI*180;
}
template <typename N> inline double sin_deg(N angle){
    return sin(deg2rad(angle));
}
template <typename N> inline double cos_deg(N angle){
    return cos(deg2rad(angle));
}
template <typename N> inline double tan_deg(N angle){
    return tan(deg2rad(angle));
}
template <typename N> inline double asin_deg(N angle){
    return asin(deg2rad(angle));
}
template <typename N> inline double acos_deg(N angle){
    return acos(deg2rad(angle));
}
template <typename N> inline double atan_deg(N angle){
    return atan(deg2rad(angle));
}
//atan2 takes all 4 quadrants into account
template <typename N> inline double atan2_deg(N angle){
    return atan2(deg2rad(angle));
}