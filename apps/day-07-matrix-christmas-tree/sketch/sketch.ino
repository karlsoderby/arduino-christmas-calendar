// Day 07 - Matrix Christmas Tree
// Two frames of a Christmas tree on the 8x13 built-in LED matrix.
// 0 = off, 2 = dim (branches), 7 = bright (star and ornaments).

#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;

uint8_t treeA[104] = {
  0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 7, 2, 2, 2, 2, 0, 0, 0, 0,
  0, 0, 0, 2, 2, 2, 2, 2, 7, 2, 0, 0, 0,
  0, 0, 2, 2, 7, 2, 2, 2, 2, 2, 2, 0, 0,
  0, 2, 2, 2, 2, 2, 2, 7, 2, 2, 2, 2, 0,
  2, 2, 7, 2, 2, 2, 2, 2, 2, 2, 7, 2, 2,
  0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0
};

uint8_t treeB[104] = {
  0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 2, 7, 2, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 2, 2, 2, 2, 7, 0, 0, 0, 0,
  0, 0, 0, 2, 2, 7, 2, 2, 2, 2, 0, 0, 0,
  0, 0, 2, 2, 2, 2, 2, 2, 7, 2, 2, 0, 0,
  0, 2, 2, 7, 2, 2, 2, 2, 2, 2, 7, 2, 0,
  2, 2, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2, 2,
  0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0
};

void setup() {
  matrix.begin();
  matrix.setGrayscaleBits(3);  // brightness values 0 - 7
  matrix.clear();
}

void loop() {
  matrix.draw(treeA);
  delay(600);
  matrix.draw(treeB);
  delay(600);
}
