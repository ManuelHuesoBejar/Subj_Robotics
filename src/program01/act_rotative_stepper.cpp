#include "act_rotative_stepper.hpp"

Rotative_actuator::Rotative_actuator(Rotation_sensor* s), sensor(s){}

double Rotative_actuator::get_current_pos(){
  current_pos = sensor->read_angle();
  return current_pos;
}

int Rotative_actuator::move(){
  double angle_dif = target_pos - *this.get_current_pos();
  if (angle_dif == 0) {
    stepper.stop();
    return 0;
  }
  
  //direction_inverter cambia la lógica para que cambie el sentido de giro
  direction_inverter ? stepper.startRotate(angle_dif): stepper.startRotate(-angle_dif);                     //in degrees (double)
}
