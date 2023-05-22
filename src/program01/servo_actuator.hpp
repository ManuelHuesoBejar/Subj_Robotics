#pragma once
#include "actuator.hpp"
#include "rotation_sensor.hpp"
#include <Servo.h>

class Servo_Feedback: public Actuator{
    //int pin_feedback;
    Rotation_sensor pote;
    uint8_t pin_s;
    double degree_range[2]{10, 170};
    int microsec_range[2]{700, 2300};
    public:
    Servo_Feedback(uint8_t pin_signal, uint8_t pin_pote, double spin_range_, double i_rel_ = 1.0):Actuator(), Rotation_sensor(pin_pote, spin_range_, i_rel_), 
    pin_s{pin_signal}{
      Servo myservo;
      myservo.attach(pin);
    }
    virtual ~Servo_Feedback(){myservo.detach(); delete myservo;}
    
    void begin() {pinMode(pin, OUTPUT); pinMode(pote.pin, INPUT);}

    int deg2microseconds(double grados){return map(grados, degree_range[0], degree_range[1], microsec_range[0], microsec_range[1]);}
    int inv_deg2microseconds(double grados){return map(grados, degree_range[1], degree_range[0], microsec_range[0], microsec_range[1]);}
    double microsecond2degs(int microseconds){return map(microseconds, microsec_range[0], microsec_range[1], degree_range[0], degree_range[1]);}

    void set_deg_range(double low_lim, double high_lim){degree_range[0]=low_lim; degree_range[1}=high_lim;}
    void set_micros_range(int low_lim, int high_lim){microsec_range[0]=low_lim; microsec_range[1}=high_lim;}
    
    double get_current_pos(){
      int pos = analogRead(pin_feedback);
      current_pos = microsecond2degs(pos); 
      //puede que sea mejor
      current_pos = pote.read_angle();
      return current_pos;
    }
    int move(){
      double angle_dif = target_pos - *this.get_current_pos();
      if(angle_dif == 0) return 0;
      direction_inverter ? myservo.writeMicroseconds(deg2microseconds(target_pos)):myservo.writeMicroseconds(inv_deg2microseconds(target_pos));
        //return ID;
    }
};
