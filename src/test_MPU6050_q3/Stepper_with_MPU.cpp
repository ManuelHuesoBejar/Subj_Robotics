#include "Stepper_with_MPU.hpp"

Stepper_with_MPU_feedback::Stepper_with_MPU_feedback(DRV8825* stepper_, Adafruit_MPU6050* mpu6050_) : mpu6050(mpu6050_), stepper(stepper_) {};
Stepper_with_MPU_feedback::Stepper_with_MPU_feedback(DRV8825* stepper_, Adafruit_MPU6050* mpu6050_, double lim1, double lim2)
: Stepper_with_MPU_feedback(stepper_, mpu6050_) {
  set_limits(lim1, lim2);
}

double Stepper_with_MPU_feedback::get_current_pos(){
  sensors_event_t a, g, temp;
  mpu6050->getEvent(&a, &g, &temp);
  
  current_pos = RAD_TO_DEG * atan2(-a.acceleration.y, a.acceleration.z);
  return current_pos;
}

int Stepper_with_MPU_feedback::move(){
  double angle_dif = target_pos - this->get_current_pos();
  Serial.print(current_pos); Serial.print(" "); Serial.println(angle_dif);
  if (abs(angle_dif) <= 1.) {
    stepper->stop();
    return 0;
  }

  if (millis() - last_operation > 10) {
    stepper->move((angle_dif<0) ? 1 : -1);
    last_operation = millis();
  }

  //auto wait_time = stepper->nextAction();
  //if (wait_time <= 0) {
    //direction_inverter ? stepper->startRotate(angle_dif): stepper->startRotate(-angle_dif);
    
  //}
  
  return 1;
}
