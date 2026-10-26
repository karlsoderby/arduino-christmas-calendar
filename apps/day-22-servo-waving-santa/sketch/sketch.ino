// Day 22 - Waving Santa
// A paper Santa arm is attached to a servo motor on D9.
// Button A: Santa waves hello. Button B: Santa waves slowly goodbye.

#include <Arduino_Modulino.h>
#include <Servo.h>

ModulinoButtons buttons;
Servo arm;

const int servoPin = 9;
const int ARM_DOWN = 90;   // resting angle
const int ARM_LEFT = 50;
const int ARM_RIGHT = 130;

void wave(int times, int speedMs) {
  for (int i = 0; i < times; i++) {
    arm.write(ARM_LEFT);
    delay(speedMs);
    arm.write(ARM_RIGHT);
    delay(speedMs);
  }
  arm.write(ARM_DOWN);
}

void setup() {
  Modulino.begin();
  buttons.begin();

  arm.attach(servoPin);
  arm.write(ARM_DOWN);
}

void loop() {
  if (buttons.update()) {
    if (buttons.isPressed('A')) {
      buttons.setLeds(true, false, false);
      wave(4, 250);   // fast "hello"
    } else if (buttons.isPressed('B')) {
      buttons.setLeds(false, true, false);
      wave(2, 700);   // slow "goodbye"
    }
    buttons.setLeds(false, false, false);
  }
}
