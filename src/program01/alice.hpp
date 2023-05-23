#pragma once

/* Includes */
// Sensores
#include "act_rotative_stepper.hpp"

class Alice {
    // Actuadores
    Rotative_actuator q1;
    Rotative_actuator q2;
    Rotative_actuator q3;
    Servo_Feedback q4;
    Servo_Feedback q_effector;
    public:
    Alice(Rotation_sensor* sensorQ1, DRV8825* stepperQ1, Rotation_sensor* sensorQ2, DRV8825* stepperQ2):q1(sensorQ1, stepperQ1), q2(sensorQ2, stepperQ2), 
    q4(pinQ4, pin_poteQ4, spin_range_, i_rel_ = 1.0){}

};
