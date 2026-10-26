// Day 11 - Christmas Lights
// A red-green-white pattern that moves along the 8 LEDs of the Modulino Pixels.

#include <Arduino_Modulino.h>

ModulinoPixels pixels;

ModulinoColor colors[] = { RED, GREEN, WHITE };
int offset = 0;

void setup() {
  Modulino.begin();
  pixels.begin();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    pixels.set(i, colors[(i + offset) % 3], 10);  // brightness 0 - 100
  }
  pixels.show();

  offset = (offset + 1) % 3;
  delay(300);
}
