// Day 13 - Gift Picker
// Button A shows a tree, B a star and C a gift on the built-in LED matrix.
// The LED above the last pressed button stays on.

#include <Arduino_Modulino.h>
#include <Arduino_LED_Matrix.h>

ModulinoButtons buttons;
Arduino_LED_Matrix matrix;

uint8_t tree[104] = {
  0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 7, 3, 3, 3, 3, 0, 0, 0, 0,
  0, 0, 0, 3, 3, 3, 3, 3, 7, 3, 0, 0, 0,
  0, 0, 3, 3, 7, 3, 3, 3, 3, 3, 3, 0, 0,
  0, 3, 3, 3, 3, 3, 3, 7, 3, 3, 3, 3, 0,
  3, 3, 7, 3, 3, 3, 3, 3, 3, 3, 7, 3, 3,
  0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0
};

uint8_t star[104] = {
  0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 0,
  0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0,
  0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0,
  0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0,
  0, 0, 0, 7, 7, 7, 0, 7, 7, 7, 0, 0, 0,
  0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0,
  0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0
};

uint8_t gift[104] = {
  0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 0,
  0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0,
  0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0,
  0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0,
  0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0,
  0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0,
  0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0
};

void setup() {
  Modulino.begin();
  buttons.begin();

  matrix.begin();
  matrix.setGrayscaleBits(3);  // brightness values 0 - 7
  matrix.draw(tree);
  buttons.setLeds(true, false, false);
}

void loop() {
  if (buttons.update()) {  // true when a button changed state
    if (buttons.isPressed('A')) {
      matrix.draw(tree);
      buttons.setLeds(true, false, false);
    } else if (buttons.isPressed('B')) {
      matrix.draw(star);
      buttons.setLeds(false, true, false);
    } else if (buttons.isPressed('C')) {
      matrix.draw(gift);
      buttons.setLeds(false, false, true);
    }
  }
}
