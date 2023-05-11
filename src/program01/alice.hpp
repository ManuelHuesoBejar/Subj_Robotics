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
    #define Q5_SENSOR A5
    #define CLAMP_SENSOR A8

#endif

class Alice {
    // Actuadores
    Rotative_actuator q1{};
    Rotative_actuator q2{};
    Rotative_actuator q3{};
    Servo_Feedback q4{};
    Servo_Feedback q_effector{};

    int (*direct)(const Pose& in, Node& out) = nullptr;
    int (*inverse)(const Node& in, const Pose& current, Pose& out) = nullptr;

public:
    int watchdog();
    int move();

    /** @brief Establece objetivo posición del sensor
     * Entrada de tipo Pose o Node
    */
    int set_target(const Pose& target);
    int set_target(const Node& target);

    /** @brief Establece funciones para calcular cinemáticas
    */
    int bind_kinetics_funcs(
        int (*direct)(const Pose& in, Node& out),
        int (*inverse)(const Node& in, const Pose& current, Pose& out))
};
