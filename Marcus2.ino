#include <Stepper.h>
#include <Servo.h>

//Create servo object and servo pin
Servo myServo;
const int servoPin=7;

//Initialize rotation steps
const int rotation=2048;

//Create stepper object
Stepper carStepper(rotation, 9, 11, 10, 12);

void setup() {
  //Set stepper motor speed and servo pin
  carStepper.setSpeed(10);
  myServo.attach(servoPin);
}

void loop() {
  //Stepper motor forward, then servo turn 25 degrees
  carStepper.step(rotation);
  myServo.write(25);
  delay(1000);

  carStepper.step(-rotation);
  myServo.write(0);
  delay(1000);
}
