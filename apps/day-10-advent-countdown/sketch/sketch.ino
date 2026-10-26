// Day 10 - Advent Countdown
// Python sends the number of days left until Christmas.
// The sketch scrolls the countdown on the built-in LED matrix.

#include <Arduino_RouterBridge.h>
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;

int daysLeft = -1;  // -1 = no data from Python yet

void set_days(int days) {
  daysLeft = days;
}

void setup() {
  matrix.begin();
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(80);
  matrix.clear();

  Bridge.begin();
  Bridge.provide_safe("set_days", set_days);  // runs safely between loop() calls
}

void loop() {
  String text;

  if (daysLeft < 0) {
    text = "...";
  } else if (daysLeft == 0) {
    text = "MERRY CHRISTMAS!";
  } else if (daysLeft == 1) {
    text = "1 DAY TO CHRISTMAS";
  } else {
    text = String(daysLeft) + " DAYS TO CHRISTMAS";
  }

  matrix.beginText(0, 0, 127, 0, 0);
  matrix.print("   " + text + "   ");
  matrix.endText(SCROLL_LEFT);
  delay(300);
}
