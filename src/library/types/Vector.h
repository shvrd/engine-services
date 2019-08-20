//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_VECTOR_H
#define ENGINITO_VECTOR_H

struct Vector2 {
    float x = 0, y = 0;

    Vector2() : x(0), y(0) {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}

    Vector2 operator+(const Vector2& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector2 operator-(const Vector2 rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
};

struct Vector3 {
    float x = 0, y = 0, z = 0;

    Vector3 operator+(const Vector3& rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    Vector3 operator-(const Vector3& rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }
};

#endif //ENGINITO_VECTOR_H
