//
// Created by thekatze on 24/02/2019.
//

#ifndef ENGINITO_COLOR_H
#define ENGINITO_COLOR_H

struct Color {
    unsigned char r, g, b, a;

    void set(unsigned char _r = 0, unsigned char _g = 0, unsigned char _b = 0, unsigned char _a = 0) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
};

#endif //ENGINITO_COLOR_H
