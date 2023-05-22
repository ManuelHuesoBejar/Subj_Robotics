#include <DRV8825.h>

#define STP_STEPS short(360/1.8)
#define STP_MODE0 27
#define STP_MODE1 29
#define STP_MODE2 31
#define STP1_STEP 23
#define STP1_DIR 25
#define STP2_STEP 37
#define STP2_DIR 39
#define STP3_STEP 51
#define STP3_DIR 53

DRV8825 stepper {STP_STEPS, STP3_DIR, STP3_STEP, STP_MODE0, STP_MODE1, STP_MODE2};

void setup() {
    Serial.begin(115200);
    stepper.begin(2.f, 32);
    stepper.rotate(90.);
}

void loop() {
    stepper.nextAction();
    
    Serial.print(analogRead(A0));
    Serial.print("   ");
    Serial.println(analogRead(A1));
    
}
