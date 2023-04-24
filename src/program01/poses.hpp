#pragma once

template <typename N>
struct pose{
    pose(N x=0, N y=0, N z=0, N _rx=0, N _ry=0, N _rz=0): px{x},py{y},pz{z},rx{_rx},ry{_ry},rz{_rz} {};
    N px;
    N py;
    N pz;
    N rx;
    N ry;
    N rz;
};