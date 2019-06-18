//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_VECTOR_H
#define ENGINITO_VECTOR_H

struct Vector2 {
    float x = 0, y = 0;

    void set(float _x = 0, float _y = 0) {
        x = _x;
        y = _y;
    }

    Vector2 operator+(const Vector2& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector2 operator-(const Vector2 rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
};

struct Vector3 {
    float x = 0, y = 0, z = 0;

    void set(float _x = 0, float _y = 0, float _z = 0) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3 operator+(const Vector3& rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    Vector3 operator-(const Vector3& rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }
};

#endif //ENGINITO_VECTOR_H
