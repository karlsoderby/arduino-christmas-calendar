// Day 20 - Rudolph's Star Hunt
// Move Rudolph (bright dot) with the Modulino Joystick.
// Catch the blinking star to score a point. A new star then appears somewhere else.

#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>
#include <Arduino_LED_Matrix.h>

ModulinoJoystick joystick;
Arduino_LED_Matrix matrix;

const int ROWS = 8;
const int COLS = 13;

uint8_t frame[ROWS * COLS];

int rudolphX = 6;
int rudolphY = 4;
int starX = 2;
int starY = 1;
int score = 0;
bool starOn = true;

void setup() {
  Bridge.begin();
  Monitor.begin();
  Modulino.begin();
  joystick.begin();

  matrix.begin();
  matrix.setGrayscaleBits(3);  // brightness values 0 - 7
}

void loop() {
  joystick.update();
  int x = joystick.getX();  // about -128 to 127
  int y = joystick.getY();

  // Move one step when the stick is pushed far enough
  if (x > 60 && rudolphX < COLS - 1) rudolphX++;
  if (x < -60 && rudolphX > 0) rudolphX--;
  if (y > 60 && rudolphY > 0) rudolphY--;
  if (y < -60 && rudolphY < ROWS - 1) rudolphY++;

  // Caught the star?
  if (rudolphX == starX && rudolphY == starY) {
    score++;
    Monitor.print("Star caught! Score: ");
    Monitor.println(score);
    starX = random(COLS);
    starY = random(ROWS);
  }

  // Draw: dim star that blinks, bright Rudolph
  memset(frame, 0, sizeof(frame));
  starOn = !starOn;
  if (starOn) {
    frame[starY * COLS + starX] = 3;
  }
  frame[rudolphY * COLS + rudolphX] = 7;
  matrix.draw(frame);

  delay(150);
}
