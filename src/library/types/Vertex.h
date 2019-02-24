//
// Created by thekatze on 25/01/2019.
//

#ifndef ENGINITO_VERTEX_H
#define ENGINITO_VERTEX_H

#include "Vector.h"
#include "Color.h"

struct Vertex {
    Vector3 position;
    Color color;

    Vector2 uv;
};

#endif //ENGINITO_VERTEX_H
