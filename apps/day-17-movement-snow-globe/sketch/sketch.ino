// Day 17 - Shake the Snow Globe
// Shake the Modulino Movement and snow starts falling on the LED matrix.
// Hold it still and the snow slowly settles.

#include <Arduino_Modulino.h>
#include <Arduino_LED_Matrix.h>

ModulinoMovement movement;
Arduino_LED_Matrix matrix;

const int ROWS = 8;
const int COLS = 13;

uint8_t snow[ROWS * COLS];
int snowTime = 0;  // how many more steps it keeps snowing

void setup() {
  Modulino.begin();
  movement.begin();

  matrix.begin();
  matrix.setGrayscaleBits(3);  // brightness values 0 - 7
  matrix.clear();
}

void loop() {
  movement.update();
  float x = movement.getX();
  float y = movement.getY();
  float z = movement.getZ();

  // At rest the total acceleration is about 1 g. Much more than that = shaking!
  float total = sqrt(x * x + y * y + z * z);
  if (total > 1.8) {
    snowTime = 40;
  }

  // Move every row down by one
  for (int row = ROWS - 1; row > 0; row--) {
    for (int col = 0; col < COLS; col++) {
      snow[row * COLS + col] = snow[(row - 1) * COLS + col];
    }
  }

  // New snowflakes on the top row only while it is snowing
  for (int col = 0; col < COLS; col++) {
    snow[col] = (snowTime > 0 && random(4) == 0) ? random(3, 8) : 0;
  }
  if (snowTime > 0) {
    snowTime--;
  }

  matrix.draw(snow);
  delay(120);
}
