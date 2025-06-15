#include <Arduino.h>
#include <FastLED.h>
#include <pitches.h>
#include <AudioManager.h>
#include <Note.h>
#include <Matrix.h>

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH 32

Note song[] = {
    Note(NOTE_C4, 4),
    Note(NOTE_G3, 8),
    Note(NOTE_G3, 8),
    Note(NOTE_A3, 4),
    Note(NOTE_G3, 4),
    Note(0, 4),
    Note(NOTE_B3, 4),
    Note(NOTE_C4, 4)
};

AudioManager audioManager;

Matrix matrix;
void setup() {
    matrix = Matrix(MATRIX_WIDTH, MATRIX_HEIGHT, 1, 1, 80);

    audioManager = AudioManager(8);
    audioManager.playSong(song, sizeof(song) / sizeof(Note));
}

void loop() {
    // audioManager.update();
    delay(500);

    for (int i = 0; i < MATRIX_WIDTH; i++) {
        for (int k = 0; k < MATRIX_HEIGHT; k++) {
            matrix.setPixel(k, i, CRGB::Green);
            FastLED.show();
            delay(25);
        }
    }

    delay(500);
    FastLED.clear();
}
