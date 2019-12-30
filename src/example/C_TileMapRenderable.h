//
// Created by thekatze on 17/11/2019.
//

#ifndef SHVRD_C_TILEMAPRENDERABLE_H
#define SHVRD_C_TILEMAPRENDERABLE_H

#include <memory>

#include <components/Component.h>
#include <components/Entity.h>
#include <services/graphics/Shader.h>
#include <services/graphics/Graphics.h>
#include <services/GraphicsServiceLocator.h>
#include "C_TileMap.h"

class C_TileMapRenderable : public Component {
    std::shared_ptr<Shader> m_shader;

public:
    explicit C_TileMapRenderable(std::shared_ptr<Shader> shader)
        : m_shader(std::move(shader)) {}

    void render() override;
};

void C_TileMapRenderable::render() {
    C_TileMap* tileMapComponent = getParent()->getComponent<C_TileMap>();
    std::shared_ptr<Graphics> graphics = GraphicsServiceLocator::get();

    unsigned int tileWidth = tileMapComponent->getTileWidth();
    unsigned int tileHeight = tileMapComponent->getTileHeight();

    graphics->bindShader(m_shader);

    for (unsigned int x = 0; x < tileMapComponent->getWidth(); ++x) {
        for (unsigned int y = 0; y < tileMapComponent->getHeight(); ++y) {
            const Tile& tile = tileMapComponent->getTileAt(x, y);

            if (tile.m_textureId == 0)
                continue;

            graphics->useTexture(std::make_shared<Texture>(Texture{.id = tile.m_textureId, .width = 0, .height = 0}));
            graphics->drawToRect({(float) x * tileWidth, (float) y * tileHeight}, { (float) tileWidth, (float) tileHeight}, 0.f);
        }
    }

    m_shader->unbind();
}

#endif //SHVRD_C_TILEMAPRENDERABLE_H
