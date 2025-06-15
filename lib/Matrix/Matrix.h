#ifndef MATRIX_H
#define MATRIX_H

#include <FastLED.h>
#include <vector>

#define DATA_PIN 4

// TODO: Make this class a Singleton
class Matrix {
    std::vector<CRGB> leds;

    public:
        int width{};
        int height{};
        int numberOfMatrices{};
        uint8_t maximumAmperes{};
        uint8_t brightness{};
        int ledsCount{};

        Matrix(int width, int height, int numberOfMatrices, uint8_t maximumAmperes, uint8_t brightness);
        Matrix() = default;

        [[nodiscard]] int flattenCoordinates(int x, int y) const;
        void setPixel(int x, int y, const CRGB& color);

};

#endif //MATRIX_H
