//
// Created by thekatze on 17/11/2019.
//

#ifndef SHVRD_C_RENDERABLE_H
#define SHVRD_C_RENDERABLE_H

#include <memory>

#include "../Component.h"
#include "../../services/graphics/Shader.h"
#include "../../services/graphics/Sprite.h"
#include "../../services/GraphicsServiceLocator.h"

#include "C_Transform.h"

class C_Renderable : public Component {
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Sprite> m_sprite;
public:
    C_Renderable(std::shared_ptr<Shader> shader, std::shared_ptr<Sprite> sprite)
        : m_shader(std::move(shader))
        , m_sprite(std::move(sprite)) {}

    void render() override;
};

void C_Renderable::render() {
    std::shared_ptr<Graphics> graphics = GraphicsServiceLocator::get();
    graphics->bindShader(m_shader);

    C_Transform* transform = getParent()->getComponent<C_Transform>();

    if (transform) {
        m_sprite->setLocation(transform->m_location);
        m_sprite->setRotation(transform->m_rotation);
        m_sprite->setScale(transform->m_scale);
    }

    graphics->drawSprite(m_sprite);
    m_shader->unbind();
}

#endif //SHVRD_C_RENDERABLE_H
