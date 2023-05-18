#pragma once

/* Includes */
// Sensores
#include "act_rotative_stepper.hpp"
#include "servo_actuator.hpp"

// Kinetics
#include "kinetics/nodes.hpp"
#include "kinetics/poses.hpp"

/* Definiciones entorno */
// Pines y plataforma-específico
#ifdef ARDUINO_AVR_MEGA2560
    #define Q1_SENSOR A1
    #define Q2_SENSOR A2
    #define Q4_SENSOR A4
    #define CLAMP_SENSOR A8

#endif

class Alice {
    // Pose destino
    Pose target_pose;
    Node target_node;

    // Actuadores
    Rotative_actuator q1{};
    Rotative_actuator q2{};
    Rotative_actuator q3{};
    Servo_Feedback q4{};
    Servo_Feedback q_effector{};

    //Definimos las longitudes del robot
    const double l1; //longitud de la columna central
    const double l2; //longitud de la articulacion prismatica
    const double l3; //Longitud (en eje y) ente la prismatica y el codo
    const double l4; //longitud del brazo
    const double l5; //longitud efector final


public:
    int watchdog();
    int move();

    /** @brief Establece objetivo posición del sensor
     * Entrada de tipo Pose o Node
     * Se actualizan mutuamente
    */
    int set_target(const Pose& target);
    int set_target(const Node& target);

    /** @brief Obtiene Pose o Nodo actual
    */
    Node get_current_node();
    Pose get_current_pose();

    int inverse(const Node& in, Pose& out);
    int direct(const Pose& in, Node& out);
};
