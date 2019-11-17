//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_VECTOR_H
#define ENGINITO_VECTOR_H

struct Vector2f {
    float x = 0, y = 0;

    Vector2f() : x(0), y(0) {}
    Vector2f(float _x, float _y) : x(_x), y(_y) {}

    Vector2f operator+(const Vector2f& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector2f operator+=(const Vector2f& rhs) {
        return *this = *this + rhs;
    }

    Vector2f operator-(const Vector2f rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
};

struct Vector3f {
    float x = 0, y = 0, z = 0;

    Vector3f operator+(const Vector3f& rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    Vector3f operator+=(const Vector3f& rhs) {
        return *this = *this + rhs;
    }

    Vector3f operator-(const Vector3f& rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }
};

#endif //ENGINITO_VECTOR_H
