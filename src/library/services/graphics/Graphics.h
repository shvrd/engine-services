//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_GRAPHICS_H
#define ENGINITO_GRAPHICS_H

#include <memory>
#include "../../types/Color.h"
#include "Shader.h"
#include "Sprite.h"

class Graphics {
public:
    Graphics() = default;
    virtual ~Graphics() = default;

    virtual void clear() = 0;
    virtual void setClearColor(Color color) = 0;

    virtual void initialize(int windowWidth, int windowHeight) = 0;

    virtual void setViewport(int width, int height) = 0;

    //TODO: Maybe make a standalone shaderfactory?
    virtual std::unique_ptr<Shader> createShader() = 0;
    virtual std::unique_ptr<Sprite> createSprite(Vector2 location, Vector2 dimensions) = 0;
};

#endif //ENGINITO_GRAPHICS_H
