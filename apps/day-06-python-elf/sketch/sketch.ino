// Day 06 - Python Elf
// The sketch provides a "set_led" function that Python can call through the Bridge.

#include <Arduino_RouterBridge.h>

void set_led(bool on) {
  digitalWrite(LED_BUILTIN, on ? LOW : HIGH);  // built-in LED is active low
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Bridge.begin();
  Bridge.provide("set_led", set_led);
}

void loop() {
}
