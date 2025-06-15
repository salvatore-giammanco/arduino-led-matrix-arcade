#include <Arduino.h>
#include <AudioManager.h>
#include <Note.h>
#include <queue>


void AudioManager::update() {
    const unsigned long currentTime = millis();
    Note currentNote{};

    switch (state) {
        case IDLE:
            if (!noteQueue.empty()) {
                state = START_NOTE;
            }
            break;

        case START_NOTE:
            currentNote = noteQueue.front();

            currentNoteDuration = currentNote.millisecondsDuration();
            currentNoteTotalDuration = currentNote.millisecondsPauseDuration();
            currentNoteStartTime = currentTime;

            tone(buzzerPin, currentNote.frequency);

            state = WAIT_NOTE_END;
            break;

        case WAIT_NOTE_END:
            if (currentTime - currentNoteStartTime >= currentNoteDuration) {
                noTone(buzzerPin);
                noteQueue.pop();
                state = WAIT_PAUSE_END;
            }
            break;

        case WAIT_PAUSE_END:
            if (currentTime - currentNoteStartTime >= currentNoteTotalDuration) {
                if (noteQueue.empty()) {
                    state = IDLE;
                } else {
                    state = START_NOTE;
                }
            }
            break;
    }
}

void AudioManager::playNote(const Note note) {
    noteQueue.push(note);
}

void AudioManager::playSong(const Note* melody, const int length) {
    for (int i = 0; i < length; i++) {
        noteQueue.push(melody[i]);
    }
}