#pragma once

struct node{
    //posición p{eje}
    double px;
    double py;
    double pz;
    //rotación r{eje}
    double rx;
    double ry;
    double rz;
    node(double x=0, double y=0, double z=0, double _rx=0, double _ry=0, double _rz=0):
    px{x},py{y},pz{z},rx{_rx},ry{_ry},rz{_rz} {};
};