// Day 04 - Snow-o-Meter
// Read a potentiometer on A0 and print a "snow forecast" to the Serial Monitor.

#include <Arduino_RouterBridge.h>

const int potPin = A0;

void setup() {
  Bridge.begin();
  Monitor.begin();
}

void loop() {
  int value = analogRead(potPin);           // 0 - 1023
  int snow = map(value, 0, 1023, 0, 100);   // 0 - 100 %

  Monitor.print("Raw: ");
  Monitor.print(value);
  Monitor.print("  Snow: ");
  Monitor.print(snow);
  Monitor.print("%  ");

  if (snow < 25) {
    Monitor.println("No snow today...");
  } else if (snow < 50) {
    Monitor.println("A few snowflakes *");
  } else if (snow < 75) {
    Monitor.println("Snowing! * * *");
  } else {
    Monitor.println("BLIZZARD! * * * * * *");
  }

  delay(500);
}
