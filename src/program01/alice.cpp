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

    //Aplicamos la matriz de transformacion homogénea para obtener las coords. finales
    out.px = l3 * cos_deg(in.q1) - in.d2 * sin_deg(in.q1) + l4 * sin_deg(in.q1) * sin_deg(in.q3) + l5 * cos_deg(in.q3) * sin_deg(in.q1) * sin_deg(in.q4) + l5 * cos_deg(in.q4) * sin_deg(in.q1) * sin_deg(in.q3);
    out.py = in.d2 * cos_deg(in.q1) + l3 * sin_deg(in.q1) - l4 * cos_deg(in.q1) * sin_deg(in.q3) - l5 * cos_deg(in.q1) * cos_deg(in.q3) * sin_deg(in.q4) - l5 * cos_deg(in.q1) * cos_deg(in.q4) * sin_deg(in.q3);
    out.pz = l1 - l4 * cos_deg(in.q3) - l5 * cos_deg(in.q3) * cos_deg(in.q4) + l5 * sin_deg(in.q3) * sin_deg(in.q4);

    //Para simplificar el cálculo, solamente consideraremos la rotación del efector final en el eje y
    //ya que es la determinante para el hisopado. Dicha rotación coincide con el giro del servo del efector final
    out.rx = 0;
    out.ry = in.q4 + in.q3;
    out.rz = 0;

    //Comprobamos que la posición final se encuentre dentro de los límites del espacio de trabajo del robot
    //Colocamos el origen de coordenadas en la base. Análisis del peor caso:
    //Añadir una condicion en out.rz para que no se supere el giro maximo del servo?
    if ((out.px > (l2 / 2 + l4 + l5))||(out.px < -(l2 / 2 + l4 + l5))||
        (out.py > (l2 / 2 + l4 + l5))||(out.py < -(l2 / 2 + l4 + l5))||
        (out.pz > (l1 + l4 + l5))    ||(out.pz < (l1 - l4 - l5)))
    {
        return 1;
    }

    else return 0;
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

    //Hay que añadirle condiciones para limitar las rotaciones de los servos
    if ((d > l2 / 2 || d < l2 / 2))
    {
        return 1
    }

    else{
    out.d2 = d;
    out.q3 = deg2rad(alpha);
    out.q4 = deg2rad(beta);
    return 0;
    }
}