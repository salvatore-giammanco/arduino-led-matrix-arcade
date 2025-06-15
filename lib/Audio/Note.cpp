#include "Note.h"

Note::Note(const int frequency, const int duration)
    : frequency(frequency), duration(duration) {}

int Note::millisecondsDuration() const {
    return 1000 / duration;
}

int Note::millisecondsPauseDuration() const {
    return millisecondsDuration() * 1.30;
}