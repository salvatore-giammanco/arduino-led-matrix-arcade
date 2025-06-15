#include <Matrix.h>
#include <FastLED.h>



Matrix::Matrix(
    const int width,
    const int height,
    const int numberOfMatrices,
    const uint8_t maximumAmperes,
    const uint8_t brightness
) :width(width), height(height), numberOfMatrices(numberOfMatrices), brightness(brightness) {
    ledsCount = width * height * numberOfMatrices;
    leds = std::vector<CRGB>(ledsCount, CRGB::Black);

    CFastLED::addLeds<WS2812B, DATA_PIN, GRB>(&leds[0], ledsCount);
    FastLED.setBrightness(brightness);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, maximumAmperes * 1000);
    FastLED.clear();
    FastLED.show();
}

void Matrix::setPixel(int x, int y, const CRGB& color) {
    if (const int index = flattenCoordinates(x, y); index >= 0 && index < ledsCount) {
        leds[index] = color;
    }
    FastLED.show();
}


int Matrix::flattenCoordinates(const int x, const int y) const {
    // TODO: Implement handling of multiple matrices
    if (y % 2 == 0) {
        return height * y + x;
    }
    return height * y + (height - x - 1);
}
