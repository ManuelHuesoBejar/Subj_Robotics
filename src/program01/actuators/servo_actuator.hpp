#pragma once
#include "actuator.hpp"
#include "sensors/rotation_sensor.hpp"
#include <Servo.h>

int deg2microseconds(double grados){return map(grados, 10, 170, 700, 2300);}
double microsecond2degs(int microseconds){return map(microseconds, 700, 2300, 10, 170);}

class Servo_Feedback: public Actuator {
    Servo servo;
    Rotation_sensor pote;
    uint8_t pin_s;
    public:
    Servo_Feedback(uint8_t pin_signal, uint8_t pin_pote, double spin_range_, double i_rel_ = 1.0): Actuator(), pote(pin_pote, spin_range_, i_rel_), 
    pin_s{pin_signal}{
      Servo myservo;
      myservo.attach(pin_s);
    }
    virtual ~Servo_Feedback(){servo.detach(); delete servo;}
    
    void begin() {pinMode(pin_s, OUTPUT); pinMode(pote.pin, INPUT);}
    
    double get_current_pos(){
      int pos = analogRead(pin_feedback);
      current_pos = microsecond2degs(pos); 
      //puede que sea mejor
      current_pos = pote.read_angle();
    }
    int move(){
        myservo.writeMicroseconds(deg2microseconds(target_pos));
        //return ID;
    }
};
