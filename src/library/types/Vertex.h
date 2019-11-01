//
// Created by thekatze on 25/01/2019.
//

#ifndef ENGINITO_VERTEX_H
#define ENGINITO_VERTEX_H

#include "Vector.h"
#include "Color.h"

struct Vertex {
    Vector3f position;
    Color color;

    Vector2f uv;
};

#endif //ENGINITO_VERTEX_H
