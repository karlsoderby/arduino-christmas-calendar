// Day 18 - Night-time Tree
// When the Modulino Light measures less light than DARK_LUX,
// the Modulino Pixels switch on warm white tree lights.

#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>

ModulinoLight light;
ModulinoPixels pixels;

const int DARK_LUX = 50;

ModulinoColor warmWhite(255, 120, 20);

void setup() {
  Bridge.begin();
  Monitor.begin();
  Modulino.begin();
  light.begin();
  pixels.begin();
}

void loop() {
  light.update();
  int lux = light.getLux();

  Monitor.print("Light: ");
  Monitor.print(lux);
  Monitor.println(" lux");

  for (int i = 0; i < 8; i++) {
    if (lux < DARK_LUX) {
      pixels.set(i, warmWhite, 20);
    } else {
      pixels.clear(i);
    }
  }
  pixels.show();

  delay(500);
}
