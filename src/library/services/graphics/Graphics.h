//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_GRAPHICS_H
#define ENGINITO_GRAPHICS_H

#include <memory>
#include "Shader.h"

class Graphics {
public:
    Graphics() = default;
    virtual ~Graphics() = default;

    virtual void clear() = 0;
    virtual void setClearColor() = 0;

    virtual void initialize(int windowWidth, int windowHeight) = 0;

    virtual void drawSquare() = 0;

    //TODO: Maybe make a standalone shaderfactory?
    virtual std::unique_ptr<Shader> createShader() = 0;
};

#endif //ENGINITO_GRAPHICS_H
