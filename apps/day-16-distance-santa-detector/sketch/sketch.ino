// Day 16 - Santa Detector
// When something comes closer than 20 cm to the Modulino Distance,
// the Modulino Buzzer beeps and a message is printed.

#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>

ModulinoDistance distance;
ModulinoBuzzer buzzer;

const int TRIGGER_MM = 200;  // 20 cm

void setup() {
  Bridge.begin();
  Monitor.begin();
  Modulino.begin();
  distance.begin();
  buzzer.begin();
}

void loop() {
  if (distance.available()) {
    int mm = distance.get();

    if (mm > 0 && mm < TRIGGER_MM) {
      Monitor.print("HO HO HO! Santa spotted at ");
      Monitor.print(mm);
      Monitor.println(" mm");

      buzzer.tone(1047, 150);
      delay(200);
      buzzer.tone(784, 150);
      delay(800);
    }
  }
  delay(50);
}
