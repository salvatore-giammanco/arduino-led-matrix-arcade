//
// Created by Salvatore Giammanco on 14/06/25.
//
#ifndef AUDIO_H
#define AUDIO_H
#include <Note.h>
#include <queue>

enum AudioState {
    IDLE,
    START_NOTE,
    WAIT_NOTE_END,
    WAIT_PAUSE_END
};

class AudioManager {
    int buzzerPin{};
    AudioState state = IDLE;
    unsigned long currentNoteStartTime = 0;
    int currentNoteDuration = 0;
    int currentNoteTotalDuration = 0;
    std::queue<Note> noteQueue;

    public:
        AudioManager() = default;
        explicit AudioManager(const int pin) : buzzerPin(pin) {
            pinMode(buzzerPin, OUTPUT);
        }

        void update();
        void playNote(Note note);
        void playSong(const Note* melody, int length);
};
#endif //AUDIO_H