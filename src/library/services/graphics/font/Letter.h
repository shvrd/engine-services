//
// Created by thekatze on 26/10/2019.
//

#ifndef SHVRD_LETTER_H
#define SHVRD_LETTER_H

struct Letter {
    unsigned long id;
    unsigned int textureId;
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
        long x;
        long y;
    } advance;
};

#endif //SHVRD_LETTER_H
