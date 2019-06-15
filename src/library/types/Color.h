//
// Created by thekatze on 24/02/2019.
//

#ifndef ENGINITO_COLOR_H
#define ENGINITO_COLOR_H

#include <limits>

struct Color {
    unsigned char r, g, b;

    // use full opacity by default
    unsigned char a = 255;

    void set(unsigned char _r = 0, unsigned char _g = 0, unsigned char _b = 0, unsigned char _a = 255) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

    Color operator+(const Color& rhs) const {
        Color newColor = {0, 0, 0};

        newColor.r = safeAdd(r, rhs.r);
        newColor.g = safeAdd(g, rhs.g);
        newColor.b = safeAdd(b, rhs.b);

        return newColor;
    }

    Color operator-(const Color& rhs) const {
        Color newColor = {0, 0, 0};

        newColor.r = safeSub(r, rhs.r);
        newColor.g = safeSub(g, rhs.g);
        newColor.b = safeSub(b, rhs.b);

        return newColor;
    }

    Color operator*(const Color& rhs) const {
        Color newColor = {0, 0, 0};

        unsigned char maxValue = std::numeric_limits<unsigned char>::max();

        newColor.r = (r / (float) maxValue) * (rhs.r / (float) maxValue) * maxValue;
        newColor.g = (g / (float) maxValue) * (rhs.g / (float) maxValue) * maxValue;
        newColor.b = (b / (float) maxValue) * (rhs.b / (float) maxValue) * maxValue;

        return newColor;
    }

    Color operator/(const Color& rhs) const {
        Color newColor = {0, 0, 0};

        newColor.r = rhs.r == 0 ? 255 : r / rhs.r;
        newColor.g = rhs.r == 0 ? 255 : r / rhs.r;
        newColor.b = rhs.r == 0 ? 255 : r / rhs.r;

        return newColor;
    }

    bool operator==(const Color& rhs) const {
        return r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a;
    }

private:
    unsigned char safeAdd(const unsigned char a, const unsigned char b) const {
        unsigned char result = a + b;

        if (result < a || result < b) {
            result = std::numeric_limits<unsigned char>::max();
        }

        return result;
    }

    unsigned char safeSub(const unsigned char a, const unsigned char b) const {
        unsigned char result = a + b;

        if (result > a || result > b) {
            result = std::numeric_limits<unsigned char>::min();
        }

        return result;
    }
};

namespace Colors {
    const Color WHITE = {255, 255, 255};
    const Color BLACK = {0, 0, 0};

    const Color GRAY = {128, 128, 128};
    const Color GREY = GRAY;

    const Color SILVER = {192, 192, 192};

    const Color RED = {255, 0, 0};
    const Color MAROON = {128, 0, 0};

    const Color LIME = {0, 255, 0};
    const Color GREEN = {0, 128, 0};

    const Color BLUE = {0, 0, 255};
    const Color NAVY = {0, 0, 128};
}

#endif //ENGINITO_COLOR_H
