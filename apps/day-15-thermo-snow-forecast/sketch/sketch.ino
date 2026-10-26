// Day 15 - Snow Forecast
// Read the temperature from the Modulino Thermo and scroll it on the LED matrix.
// Below 2 °C the forecast says SNOW!

#include <Arduino_Modulino.h>
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>

ModulinoThermo thermo;
Arduino_LED_Matrix matrix;

void setup() {
  Modulino.begin();
  thermo.begin();

  matrix.begin();
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(80);
  matrix.clear();
}

void loop() {
  float temperature = thermo.getTemperature();

  String text = String(temperature, 1) + " C";
  if (temperature < 2.0) {
    text += "  SNOW!";
  } else {
    text += "  NO SNOW";
  }

  matrix.beginText(0, 0, 127, 0, 0);
  matrix.print("   " + text + "   ");
  matrix.endText(SCROLL_LEFT);
}
