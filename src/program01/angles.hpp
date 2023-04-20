#pragma once
#include <math.h>

template <typename N> inline N deg2rad(N angle){
    return angle/180*PI;
}
template <typename N> inline N rad2deg(N angle){
    return angle/PI*180;
}
template <typename N> inline N sin_deg(N angle){
    return sin(deg2rad(angle));
}
template <typename N> inline N cos_deg(N angle){
    return cos(deg2rad(angle));
}
template <typename N> inline N tan_deg(N angle){
    return tan(deg2rad(angle));
}
template <typename N> inline N asin_deg(N arg){
    return rad2deg(asin(arg));
}
template <typename N> inline N acos_deg(N arg){
    return rad2deg(acos(arg));
}
template <typename N> inline N atan_deg(N arg1, N arg2){
    return rad2deg(atan(arg1, arg2));
}
//atan2 takes all 4 quadrants into account
template <typename N> inline N atan2_deg(N arg1, N arg2){
    return rad2deg(atan2(arg1, arg2));
}