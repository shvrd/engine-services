//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_VECTOR_H
#define ENGINITO_VECTOR_H

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

#endif //ENGINITO_VECTOR_H
