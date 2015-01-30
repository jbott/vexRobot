#include <vexRemote.h>
#include <vexMotor.h>

#define LEFT_PIN  10
#define RIGHT_PIN 11

#define LEFT_CHAN  3
#define RIGHT_CHAN 2

vexRemote remote;
vexMotor lMotor, rMotor;

void setup()
{
    // SUPER IMPORANT. THE REMOTE WILL NOT WORK WITHOUT THIS
    remote.setup();

    // Starts the serial debugging port
    Serial.begin(9600);
    Serial.println("Serial Started");

    // Set the two motor pin numbers
    lMotor.attach(LEFT_PIN);
    rMotor.attach(RIGHT_PIN);
}

void loop()
{
    // Prints the two channels to the serial port
    Serial.print(remote.GetChannelRaw(LEFT_CHAN));
    Serial.print(" ");
    Serial.print(remote.GetChannelRaw(RIGHT_CHAN));
    Serial.print(" ");
    Serial.print(remote.PrintStatus());
    Serial.println();

    // Set each motor to a remote channel
    lMotor.write(-remote.GetChannel(LEFT_CHAN));
    rMotor.write(remote.GetChannel(RIGHT_CHAN));

    // Delay so it only runs ~5 times per second
    // This is not strictly necessary, but it slows down the rate it prints to
    // the serial port
    // NOTE: This will also slow down how fast the remote setting is sampled
    // and fed back into the motors
    delay(200);
}
