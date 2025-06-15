#ifndef NOTE_H
#define NOTE_H
struct Note {
    int frequency;
    int duration;

    [[nodiscard]] int millisecondsDuration() const;

    [[nodiscard]] int millisecondsPauseDuration() const;

    Note() = default;

    Note(int frequency, int duration);
};
#endif //NOTE_H
