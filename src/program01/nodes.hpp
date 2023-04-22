#pragma once
#include "poses.hpp"

template <typename N>
struct node{
    pose npose;
    N rx;
    N ry;
    N rz;
    node(N x=0, N y=0, N z=0, N _rx=0, N _ry=0, N _rz=0): npose{x,y,z},rx{_rx},ry{_ry},rz{_rz} {};
};