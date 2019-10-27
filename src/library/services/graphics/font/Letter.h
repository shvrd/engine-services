//
// Created by thekatze on 26/10/2019.
//

#ifndef ENGINITO_LETTER_H
#define ENGINITO_LETTER_H

struct Letter {
    struct Bitmap {
        unsigned char* buffer;
        unsigned int width;
        unsigned int height;
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
