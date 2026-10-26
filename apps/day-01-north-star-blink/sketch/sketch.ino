// Day 01 - North Star Blink
// Twinkle the built-in LED like a star: two quick flashes, then a pause.

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // HIGH = off (the built-in LED is active low)
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // on
  delay(150);
  digitalWrite(LED_BUILTIN, HIGH);  // off
  delay(150);
  digitalWrite(LED_BUILTIN, LOW);   // on
  delay(150);
  digitalWrite(LED_BUILTIN, HIGH);  // off
  delay(1000);
}
