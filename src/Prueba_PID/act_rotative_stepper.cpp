#include "act_rotative_stepper.hpp"

Rotative_actuator::Rotative_actuator(Rotation_sensor* sensor_, DRV8825* stepp) : sensor(sensor_), stepper(stepp) {};
Rotative_actuator::Rotative_actuator(Rotation_sensor* sensor_, DRV8825* stepp, double lim1, double lim2)
: Rotative_actuator(sensor_, stepp) {
  set_limits(lim1, lim2);
}

double Rotative_actuator::get_current_pos(){
  current_pos = sensor->read_angle();
  return current_pos;
}

int Rotative_actuator::move(){
  double angle_dif = target_pos - this->get_current_pos();
  Serial.print(current_pos); Serial.print(" ");
  Serial.println(angle_dif);
  if (abs(angle_dif) <= 0.5) {
    stepper->stop();
    return 0;
  }

  if (millis() - last_operation > 10) {
    stepper->move((angle_dif<0) ? -1 : 1);
    last_operation = millis();
  }

  //auto wait_time = stepper->nextAction();
  //if (wait_time <= 0) {
    //direction_inverter ? stepper->startRotate(angle_dif): stepper->startRotate(-angle_dif);
    
  //}
  
  return 1;
}
