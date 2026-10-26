// Day 23 - Christmas Light Remote
// Python forwards the mode chosen on the web page. The sketch animates the Modulino Pixels.
// 0 = off, 1 = classic, 2 = candy cane, 3 = snow twinkle, 4 = golden glow

#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>

ModulinoPixels pixels;

ModulinoColor gold(255, 140, 0);

int mode = 1;
int step = 0;

void set_mode(int newMode) {
  mode = newMode;
}

void setup() {
  Modulino.begin();
  pixels.begin();

  Bridge.begin();
  Bridge.provide_safe("set_mode", set_mode);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (mode == 1) {
      // Classic: red and green swapping places
      pixels.set(i, ((i + step) % 2 == 0) ? RED : GREEN, 15);
    } else if (mode == 2) {
      // Candy cane: red and white stripes moving along
      pixels.set(i, ((i + step) % 4 < 2) ? RED : WHITE, 15);
    } else if (mode == 3) {
      // Snow twinkle: random white sparkles
      if (random(4) == 0) {
        pixels.set(i, WHITE, 25);
      } else {
        pixels.set(i, WHITE, 2);
      }
    } else if (mode == 4) {
      // Golden glow: all LEDs warm gold
      pixels.set(i, gold, 20);
    } else {
      pixels.clear(i);
    }
  }
  pixels.show();

  step++;
  delay(250);
}
