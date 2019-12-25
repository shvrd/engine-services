//
// Created by thekatze on 25/12/2018.
//

#ifndef SHVRD_NULLGRAPHICS_H
#define SHVRD_NULLGRAPHICS_H

#include "Graphics.h"
#include "NullShader.h"
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

    void useTexture(std::shared_ptr<Texture> texture) override {}

    std::shared_ptr<Shader> createShader() override { return std::make_shared<NullShader>(); }

    void drawText(const std::string& text, Vector2f location) override {}

    void drawToRect(Vector2f location, Vector2f dimensions) override {}

    void drawSprite(const std::shared_ptr<Sprite>& sprite) override {}
};

#endif //SHVRD_NULLGRAPHICS_H
