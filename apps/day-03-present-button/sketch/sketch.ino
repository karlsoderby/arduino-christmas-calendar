// Day 03 - Present Button
// Each press of the button on D2 "opens a present": the built-in LED lights up
// and the count is printed to the App Lab Serial Monitor.

#include <Arduino_RouterBridge.h>

const int buttonPin = 2;

int presents = 0;
int lastState = HIGH;

void setup() {
  Bridge.begin();
  Monitor.begin();
  pinMode(buttonPin, INPUT_PULLUP);  // pressed = LOW
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // off (active low)
}

void loop() {
  int state = digitalRead(buttonPin);

  if (state == LOW && lastState == HIGH) {
    presents++;
    Monitor.print("Present opened! Total: ");
    Monitor.println(presents);
  }

  digitalWrite(LED_BUILTIN, state);  // LED on while the button is held
  lastState = state;
  delay(20);                         // simple debounce
}
