#include <vexMotor.h>

#define MOTOR_PIN 11

vexMotor motor;

void setup()
{
    // Starts the serial debugging port
    Serial.begin(9600);
    Serial.println("Serial Started");

    // Set the motor pin number
    motor.attach(MOTOR_PIN);
}

void loop()
{
    // Full forward
    Serial.println("Full forward");
    motor.write(255);
    delay(1000);

    // Stop
    Serial.println("Stop");
    motor.write(0);
    delay(1000);

    // Half reverse
    Serial.println("Half reverse");
    motor.write(-128);
    delay(1000);

    // Stop
    Serial.println("Stop");
    motor.write(0);
    delay(1000);
}
