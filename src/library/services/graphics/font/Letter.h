//
// Created by thekatze on 26/10/2019.
//

#ifndef ENGINITO_LETTER_H
#define ENGINITO_LETTER_H

struct Letter {
    struct Bitmap {
        int buffer;
        int width;
        int height;
    } bitmap;

    struct Offset {
        int x;
        int y;
    } offset;

    struct Advance {
        int x;
        int y;
    } advance;
};

#endif //ENGINITO_LETTER_H
