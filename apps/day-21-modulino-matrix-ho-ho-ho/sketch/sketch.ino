// Day 21 - Ho Ho Ho Sign
// Scroll Christmas messages across the Modulino LED Matrix.

#include <ArduinoGraphics.h>
#include <Modulino_LED_Matrix.h>

ModulinoLEDMatrix matrix;

void scrollText(String text) {
  matrix.textScrollSpeed(70);
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
}

void setup() {
  matrix.begin();
}

void loop() {
  scrollText("   HO HO HO!   ");
  scrollText("   MERRY CHRISTMAS   ");
}
