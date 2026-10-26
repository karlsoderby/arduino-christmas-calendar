// Day 05 - Fireplace Dimmer
// The potentiometer on A0 sets the brightness of the LED on D9.
// A small random flicker makes it look like a cosy fire.

const int potPin = A0;
const int ledPin = 9;   // PWM pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int value = analogRead(potPin);               // 0 - 1023
  int brightness = map(value, 0, 1023, 0, 255); // 0 - 255

  int flicker = random(-30, 30);
  analogWrite(ledPin, constrain(brightness + flicker, 0, 255));

  delay(random(50, 120));
}
