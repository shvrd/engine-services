//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_NULLGRAPHICS_H
#define ENGINITO_NULLGRAPHICS_H

#include "Graphics.h"
#include "NullShader.h"
#include "NullSprite.h"

class NullGraphics : public Graphics {
public:
    NullGraphics() = default;
    ~NullGraphics() override = default;

    void clear() override {}
    void setClearColor(Color color) override {}

    void initialize(int windowWidth, int windowHeight) override {}

    void setViewport(int width, int height) override {}

    std::unique_ptr<Shader> createShader() override { return std::make_unique<NullShader>(); }
    std::unique_ptr<Sprite> createSprite(Vector2 location, Vector2 dimensions) override { return std::make_unique<NullSprite>(Vector2{0,0}, Vector2{0,0}); }
};

#endif //ENGINITO_NULLGRAPHICS_H
