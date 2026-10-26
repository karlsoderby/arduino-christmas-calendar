// Day 09 - Merry Christmas Scroller
// Scroll text across the built-in LED matrix using the ArduinoGraphics library.

#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;

void setup() {
  matrix.begin();
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(80);  // lower = faster
  matrix.clear();
}

void loop() {
  matrix.beginText(0, 0, 127, 0, 0);
  matrix.print("    MERRY CHRISTMAS!    ");
  matrix.endText(SCROLL_LEFT);
  delay(500);
}
