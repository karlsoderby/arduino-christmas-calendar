// Day 25 - Christmas Jukebox
// Python forwards the song picked on the web page.
// The sketch plays it on the Modulino Buzzer and flashes the Modulino Pixels to the beat.

#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>

ModulinoBuzzer buzzer;
ModulinoPixels pixels;

// Note frequencies in Hz
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_E6  1319
#define NOTE_F6  1397

// --- Song 1: Jingle Bells (beats in eighth notes) ---
int jingleNotes[] = {
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5
};
int jingleBeats[] = {
  2, 2, 4, 2, 2, 4,
  2, 2, 2, 2, 8,
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 4, 4
};

// --- Song 2: We Wish You a Merry Christmas ---
int wishNotes[] = {
  NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_A5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5,
  NOTE_FS5, NOTE_D5, NOTE_D5,
  NOTE_B5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_E5, NOTE_D5, NOTE_D5,
  NOTE_E5, NOTE_A5, NOTE_FS5,
  NOTE_G5
};
int wishBeats[] = {
  2,
  2, 1, 1, 1, 1,
  2, 2, 2,
  2, 1, 1, 1, 1,
  2, 2, 2,
  2, 1, 1, 1, 1,
  2, 2, 1, 1,
  2, 2, 2,
  4
};

// --- Song 3: Silent Night ---
int silentNotes[] = {
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_D6, NOTE_D6, NOTE_B5,
  NOTE_C6, NOTE_C6, NOTE_G5,
  NOTE_A5, NOTE_A5, NOTE_C6, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_A5, NOTE_A5, NOTE_C6, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_D6, NOTE_D6, NOTE_F6, NOTE_D6, NOTE_B5,
  NOTE_C6, NOTE_E6,
  NOTE_C6, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_F5, NOTE_D5,
  NOTE_C5
};
int silentBeats[] = {
  3, 1, 2, 6,
  3, 1, 2, 6,
  4, 2, 6,
  4, 2, 6,
  4, 2, 3, 1, 2,
  3, 1, 2, 6,
  4, 2, 3, 1, 2,
  3, 1, 2, 6,
  4, 2, 3, 1, 2,
  6, 6,
  3, 1, 2, 3, 1, 2,
  12
};

int songRequest = 0;  // 0 = nothing to play

void play_song(int song) {
  songRequest = song;
}

void playSong(int notes[], int beats[], int count, int eighthMs) {
  for (int i = 0; i < count; i++) {
    int duration = beats[i] * eighthMs;

    // Light one LED per note, alternating red and green
    pixels.clear();
    pixels.set(i % 8, (i % 2 == 0) ? RED : GREEN, 25);
    pixels.show();

    buzzer.tone(notes[i], duration * 0.9);
    delay(duration);
  }
  pixels.clear();
  pixels.show();
}

void setup() {
  Modulino.begin();
  buzzer.begin();
  pixels.begin();

  Bridge.begin();
  Bridge.provide_safe("play_song", play_song);
}

void loop() {
  int song = songRequest;
  songRequest = 0;

  if (song == 1) {
    playSong(jingleNotes, jingleBeats, sizeof(jingleNotes) / sizeof(int), 125);
  } else if (song == 2) {
    playSong(wishNotes, wishBeats, sizeof(wishNotes) / sizeof(int), 150);
  } else if (song == 3) {
    playSong(silentNotes, silentBeats, sizeof(silentNotes) / sizeof(int), 200);
  }
}
