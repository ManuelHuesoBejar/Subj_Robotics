#pragma once

template <typename N> inline N deg2rad(N);
template <typename N> inline N rad2deg(N angle);
//wraped math.h functions which work in radians, to work with degrees
//in this case, since trigonometric functions return a double, I made it so x_deg functions also 
//return a double instead of any type
template <typename N> inline double sin_deg(N angle);
template <typename N> inline double cos_deg(N angle);
template <typename N> inline double tan_deg(N angle);
template <typename N> inline double asin_deg(N angle);
template <typename N> inline double acos_deg(N angle);
template <typename N> inline double atan_deg(N angle);
//atan2 takes all 4 quadrants into account
template <typename N> inline double atan2_deg(N angle);