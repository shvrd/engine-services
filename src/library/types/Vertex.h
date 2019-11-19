//
// Created by thekatze on 25/01/2019.
//

#ifndef SHVRD_VERTEX_H
#define SHVRD_VERTEX_H

#include "Vector.h"
#include "Color.h"

struct Vertex {
    Vector3f position;
    Color color;

    Vector2f uv;

    bool operator==(const Vertex& rhs) {
        return (position == rhs.position && color == rhs.color && uv == rhs.uv);
    }
};

#endif //SHVRD_VERTEX_H
