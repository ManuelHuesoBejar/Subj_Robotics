#include "kinetics_alice.hpp"
#include"../angles.hpp"

//Definimos las longitudes del robot
const double l1; //longitud de la columna central
const double l2; //longitud de la articulacion prismatica
const double l3; //Longitud (en eje y) ente la prismatica y el codo
const double l4; //longitud del brazo
const double l5; //longitud efector final
const double teta_f; //ángulo de diseño en grados

int
kinetics::alice_direct(const Pose& in, Node& out) {
    
    //Aplicamos la matriz de transformacion homogénea para obtener las coords. finales
    out.px = l3 * cos_deg(in.q1) - in.d2 * sin_deg(in.q1) + l4 * sin_deg(in.q1) * sin_deg(in.q3) + l5 * cos_deg(in.q3)) * sin_deg(in.q1) * sin_deg(in.q4) + l5 * cos_deg(in.q4) * sin_deg(in.q1) * sin_deg(in.q3);
    out.py = in.d2 * cos_deg(in.q1) + l3 * sin_deg(in.q1) - l4 * cos_deg(in.q1) * sin_deg(in.q3) - l5 * cos_deg(in.q1) * cos_deg(in.q3) * sin_deg(in.q4) - l5 * cos_deg(in.q1) * cos_deg(in.q4) * sin_deg(in.q3);
    out.pz = l1 - l4 * cos_deg(in.q3) - l5 * cos_deg(in.q3) * cos_deg(in.q4) + l5 * sin_deg(in.q3) * sin_deg(in.q4);

    //Para simplificar el cálculo, solamente consideraremos la rotación del efector final en el eje y
    //ya que es la determinante para el hisopado. Dicha rotación coincide con el giro del servo del efector final
    out.rx = 0;
    out.ry = in.q4; //se podría considerar q3 + q4 tambien 
    out.rz = 0;

}

int
kinetics::alice_inverse(const Node& in, Pose& out) {
    
    double teta_final = deg2rad(teta_f);
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
