#include <Arduino.h>
#include <FastLED.h>
#include <pitches.h>

#define NUM_LEDS 256
#define DATA_PIN 4
#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH 32

CRGB leds[NUM_LEDS];

// notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };

int flat_matrix(int x, int y){
    if (y % 2 == 0) {
        return MATRIX_HEIGHT * y + x;
    }
    return MATRIX_HEIGHT * y + (MATRIX_HEIGHT - x - 1);
}

void play_song() {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        const int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        const int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
    }
}

void setup() {
    CFastLED::addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(100);
    FastLED.clear();
}

void loop() {
    play_song();
    for (int i=0; i<MATRIX_WIDTH; i++) {
        for (int k=0; k<MATRIX_HEIGHT; k++) {
            leds[flat_matrix(k,i)] = CRGB::Red;
            FastLED.show();
            delay(100);
        }
    }
    FastLED.clear();
    FastLED.show();
    delay(1000);

}

