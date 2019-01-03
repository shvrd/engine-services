//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_NULLGRAPHICS_H
#define ENGINITO_NULLGRAPHICS_H

#include "Graphics.h"

class NullGraphics : public Graphics {
public:
    NullGraphics() = default;
    ~NullGraphics() override = default;

    void clear() override {}
    void setClearColor() override {}

    void initialize(int windowWidth, int windowHeight) override {}
};

#endif //ENGINITO_NULLGRAPHICS_H
