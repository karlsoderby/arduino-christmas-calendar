// Day 12 - Jingle Bells
// Play the chorus of Jingle Bells on the Modulino Buzzer.

#include <Arduino_Modulino.h>

ModulinoBuzzer buzzer;

// Note frequencies in Hz
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784

const int BEAT = 250;  // length of one beat in milliseconds

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5,
  NOTE_C5
};

// Length of each note, in beats
int beats[] = {
  1, 1, 2,
  1, 1, 2,
  1, 1, 1, 1, 4,
  1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1,
  2, 2,
  1, 1, 2,
  1, 1, 2,
  1, 1, 1, 1, 4,
  1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1,
  4
};

const int NOTES = sizeof(melody) / sizeof(melody[0]);

void setup() {
  Modulino.begin();
  buzzer.begin();
}

void loop() {
  for (int i = 0; i < NOTES; i++) {
    int duration = beats[i] * BEAT;
    buzzer.tone(melody[i], duration * 0.9);  // short gap between notes
    delay(duration);
  }

  delay(3000);  // wait before playing again
}
