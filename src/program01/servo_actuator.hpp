#pragma once
#include "actuator.hpp"

class Servo_Feedback: public Actuator{
    int pin_feedback;
    int pin;
    public:
    Servo_Feedback():Actuator(){this->set_limits(0, 180);}
    void get_current_pos(){analogRead(pin_feedback);}
    int move(){
        //servo(target_pos);
        //digitalWrite(pin);
        //if error return ID
    }
};