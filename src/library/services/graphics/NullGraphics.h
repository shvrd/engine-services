//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_NULLGRAPHICS_H
#define ENGINITO_NULLGRAPHICS_H

#include "Graphics.h"
#include "NullShader.h"
#include "NullSprite.h"
#include "../../resources/Texture.h"

class NullGraphics : public Graphics {
public:
    NullGraphics() = default;
    ~NullGraphics() override = default;

    void clear() override {}
    void setClearColor(Color color) override {}

    void initialize(int windowWidth, int windowHeight) override {}

    void setViewport(int width, int height) override {}

    std::shared_ptr<Texture> loadTexture(const std::string& filePath) override { return std::make_shared<Texture>(); }

    void useTexture(const Texture& texture) override {}

    std::shared_ptr<Shader> createShader() override { return std::make_shared<NullShader>(); }
    std::shared_ptr<Sprite> createSprite(Vector2 location, Vector2 dimensions) override { return std::make_shared<NullSprite>(Vector2{0,0}, Vector2{0,0}); }
};

#endif //ENGINITO_NULLGRAPHICS_H
