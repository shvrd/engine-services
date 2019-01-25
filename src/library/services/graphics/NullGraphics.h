//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_NULLGRAPHICS_H
#define ENGINITO_NULLGRAPHICS_H

#include "Graphics.h"
#include "NullShader.h"

class NullGraphics : public Graphics {
public:
    NullGraphics() = default;
    ~NullGraphics() override = default;

    void clear() override {}
    void setClearColor() override {}

    void initialize(int windowWidth, int windowHeight) override {}

    void drawSquare() override {}

    std::unique_ptr<Shader> createShader() override { return std::make_unique<NullShader>(); }
};

#endif //ENGINITO_NULLGRAPHICS_H
