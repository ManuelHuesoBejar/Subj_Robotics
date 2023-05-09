#pragma once

struct Pose{
    //puesto en este orden ya que los últimos grados creo que se cambiarán más
    Pose(double t4=0, double t3=0, double l2=0, double t1=0):
    q1{t1},d2{l2},q3{t3},q4{t4} {};
    //grado de la base
    double q1;
    //prismático
    double d2;
    //rotativo en prismática
    double q3;
    //última rotativa
    double q4;
};