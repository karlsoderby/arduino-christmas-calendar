// Day 14 - Light Up the Tree
// Turn the Modulino Knob to light 0 - 8 LEDs on the Modulino Pixels.
// Press the knob to turn all lights off.

#include <Arduino_Modulino.h>

ModulinoKnob knob;
ModulinoPixels pixels;

void setup() {
  Modulino.begin();
  knob.begin();
  pixels.begin();
  knob.set(0);
}

void loop() {
  int lights = knob.get();

  // Keep the value between 0 and 8
  if (lights < 0) {
    lights = 0;
    knob.set(0);
  }
  if (lights > 8) {
    lights = 8;
    knob.set(8);
  }

  if (knob.isPressed()) {
    lights = 0;
    knob.set(0);
  }

  for (int i = 0; i < 8; i++) {
    if (i < lights) {
      // Alternate red and green
      pixels.set(i, (i % 2 == 0) ? RED : GREEN, 15);
    } else {
      pixels.clear(i);
    }
  }
  pixels.show();
  delay(50);
}
