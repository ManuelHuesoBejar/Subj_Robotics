#include "act_rotative_stepper.hpp"

void setup() {
  // put your setup code here, to run once:
  Rotative_actuator rot(new Rotation_sensor sensor(pin, spin_range), new DRV8825 stepp{STP_STEPS, STP3_DIR, STP3_STEP, STP_MODE0, STP_MODE1, STP_MODE2});
  rot.set_target();
}

void loop() {
  // put your main code here, to run repeatedly:
  rot.move();
}
