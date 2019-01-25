//
// Created by thekatze on 25/01/2019.
//

#ifndef ENGINITO_VERTEX_H
#define ENGINITO_VERTEX_H

struct Vector2 {
    float x, y;

    void set(float _x = 0, float _y = 0) {
        x = _x;
        y = _y;
    }
};

struct Vector3 {
    float x, y, z;

    void set(float _x = 0, float _y = 0, float _z = 0) {
        x = _x;
        y = _y;
        z = _z;
    }
};

struct Color {
    unsigned char r, g, b, a;

    void set(unsigned char _r = 0, unsigned char _g = 0, unsigned char _b = 0, unsigned char _a = 0) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
};


struct Vertex {
    Vector3 position;
    Vector3 color;

    Vector2 uv;
};

#endif //ENGINITO_VERTEX_H
