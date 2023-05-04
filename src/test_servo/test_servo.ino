#include <Servo.h>
#include <string.h>

#define SERVO_OUT 9
#define SERVO_FB A0

static Servo servus;
static int move_angle = 0;
static String serial_out("");
static unsigned long millis_saved = 0;

void setup() {
    servus.attach(SERVO_OUT);
    Serial.begin(115200);
    Serial.println("Set, Read,");
    millis_saved = millis();

    servus.write(1);
    delay(1000);

    while (move_angle >= 0 and move_angle <= 180) {
        servus.write(move_angle);
        delay(500);
        int read = analogRead(SERVO_FB);
        // double degrees_read = read/1023.f * 360;
        serial_out=move_angle; serial_out+=", "; serial_out+=read; serial_out+=",\n";
        Serial.println(serial_out);
        move_angle += 5;
    }
}

void loop() { /*
    if (move_angle > 180) {
        move_angle = 5;
        servus.write(move_angle);
        millis_saved = millis();
    }
    else if (millis() - millis_saved > 2000) {
        servus.write(move_angle);
        delay(500);
        int read = analogRead(SERVO_FB);
        // double degrees_read = read/1023.f * 360;
        serial_out=move_angle; serial_out+=", "; serial_out+=read; serial_out+=",\n";
        Serial.println(serial_out);
        move_angle += 5;
    }
    else {
        servus.write(move_angle);
    } */
}