// Day 08 - Matrix Snowfall
// Snowflakes appear at random on the top row and fall down one row at a time.

#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;

const int ROWS = 8;
const int COLS = 13;

uint8_t snow[ROWS * COLS];

void setup() {
  matrix.begin();
  matrix.setGrayscaleBits(3);  // brightness values 0 - 7
  matrix.clear();
}

void loop() {
  // Move every row down by one, starting from the bottom
  for (int row = ROWS - 1; row > 0; row--) {
    for (int col = 0; col < COLS; col++) {
      snow[row * COLS + col] = snow[(row - 1) * COLS + col];
    }
  }

  // New snowflakes on the top row (about 1 in 6 chance per LED)
  for (int col = 0; col < COLS; col++) {
    snow[col] = (random(6) == 0) ? random(3, 8) : 0;
  }

  matrix.draw(snow);
  delay(200);
}
