// Day 24 - Cozy Christmas Thermometer
// Read the Modulino Thermo every 2 seconds and send the values to Python.

#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>

ModulinoThermo thermo;

void setup() {
  Modulino.begin();
  thermo.begin();
  Bridge.begin();
}

void loop() {
  float temperature = thermo.getTemperature();
  float humidity = thermo.getHumidity();

  Bridge.notify("thermo", temperature, humidity);
  delay(2000);
}
