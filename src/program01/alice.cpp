#include "alice.hpp"
#include "angles.hpp"

int Alice::watchdog()
{
    int error = 0;
    error += q1.watchdog();
    error += q2.watchdog();
    error += q3.watchdog();
    error += q4.watchdog();
    // error += q_effector.watchdog();
    return error;
}

int Alice::move()
{
    int error = 0;
    error += q1.move();
    error += q2.move();
    error += q3.move();
    error += q4.move();
    // error += q_effector.move();
    return error;
}

int
Alice::direct(const Pose& in, Node& out) {

    //Aplicamos la matriz de transformacion homog�nea para obtener las coords. finales
    out.px = l3 * cos_deg(in.q1) - in.d2 * sin_deg(in.q1) + l4 * sin_deg(in.q1) * sin_deg(in.q3) + l5 * cos_deg(in.q3) * sin_deg(in.q1) * sin_deg(in.q4) + l5 * cos_deg(in.q4) * sin_deg(in.q1) * sin_deg(in.q3);
    out.py = in.d2 * cos_deg(in.q1) + l3 * sin_deg(in.q1) - l4 * cos_deg(in.q1) * sin_deg(in.q3) - l5 * cos_deg(in.q1) * cos_deg(in.q3) * sin_deg(in.q4) - l5 * cos_deg(in.q1) * cos_deg(in.q4) * sin_deg(in.q3);
    out.pz = l1 - l4 * cos_deg(in.q3) - l5 * cos_deg(in.q3) * cos_deg(in.q4) + l5 * sin_deg(in.q3) * sin_deg(in.q4);

    //Para simplificar el c�lculo, solamente consideraremos la rotaci�n del efector final en el eje y
    //ya que es la determinante para el hisopado. Dicha rotaci�n coincide con el giro del servo del efector final
    out.rx = 0;
    out.ry = in.q4 + in.q3;
    out.rz = 0;

}

int
Alice::inverse(const Node& in, Pose& out) {

    double teta_final = deg2rad(in.ry);
    double z5 = l5 * sin(teta_final);
    double x5 = l5 * cos(teta_final);
    double alpha = asin((in.pz - z5) / l4); //Angulo de q3 en radianes
    double beta = (teta_final - alpha); //Angulo efector final en radianes
    double x4 = l4 * cos(alpha);
    double d = in.px - (x5 + x4);

    //Asignamos los valores obtenidos en la pose de salida 
    out.d2 = d;
    out.q3 = deg2rad(alpha);
    out.q4 = deg2rad(beta);

}