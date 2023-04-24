#pragma once

template <typename N>
struct pose{
    pose(N t1=0, N l2=0, N z=0, N _rx=0, N _ry=0, N _rz=0): q1{t1},d2{l2},q3{z},rx{_rx},ry{_ry},rz{_rz} {};
    //grado de la base
    N q1;
    //prismático
    N d2;
    //rotativo en prismática
    N q3;
    N rx;
    N ry;
    N rz;
};