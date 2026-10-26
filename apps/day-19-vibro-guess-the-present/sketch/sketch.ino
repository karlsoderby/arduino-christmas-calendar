// Day 19 - Guess the Present
// Each button "shakes" a different present with the Modulino Vibro.
// A = teddy bear (soft and long), B = drum (short hard taps), C = toy train (chug-chug).

#include <Arduino_Modulino.h>

ModulinoButtons buttons;
ModulinoVibro vibro;

void setup() {
  Modulino.begin();
  buttons.begin();
  vibro.begin();
}

void teddyBear() {
  vibro.on(1200, true, GENTLE);
}

void drum() {
  for (int i = 0; i < 4; i++) {
    vibro.on(80, true, MAXIMUM);
    delay(150);
  }
}

void toyTrain() {
  for (int i = 0; i < 3; i++) {
    vibro.on(200, true, MEDIUM);
    delay(100);
    vibro.on(200, true, MEDIUM);
    delay(400);
  }
}

void loop() {
  if (buttons.update()) {
    if (buttons.isPressed('A')) {
      buttons.setLeds(true, false, false);
      teddyBear();
    } else if (buttons.isPressed('B')) {
      buttons.setLeds(false, true, false);
      drum();
    } else if (buttons.isPressed('C')) {
      buttons.setLeds(false, false, true);
      toyTrain();
    }
    buttons.setLeds(false, false, false);
  }
}
