#pragma once
#include "actuator.hpp"
#include <Servo.h>

class Servo_Feedback: public Actuator{
    int pin_feedback;
    int pin;
    public:
    Servo_Feedback():Actuator(){
      this->set_limits(0, 180);
      Servo myservo;
      myservo.attach(pin);  // attaches the servo on pin 9 to the servo object
    }
    virtual ~Servo_Feedback(){delete myservo;}
    void get_current_pos(){
      int pos = analogRead(pin_feedback);
      pos = map(pos, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
      current_pos = (double)pos;
    }
    int move(){
        myservo.write(target_pos);
        if (expected_pos!=current_pos) return ID;
    }
};
