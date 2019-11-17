//
// Created by thekatze on 17/11/2019.
//

#ifndef ENGINITO_C_RENDERABLE_H
#define ENGINITO_C_RENDERABLE_H

#include <memory>

#include <components/Component.h>
#include <services/graphics/Shader.h>
#include <services/graphics/Sprite.h>
#include <services/GraphicsServiceLocator.h>
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
    GraphicsServiceLocator::get()->bindShader(m_shader);
    GraphicsServiceLocator::get()->useTexture(m_sprite->getTexture());

    C_Transform* transform = getParent()->getComponent<C_Transform>();

    if (transform) {
        m_sprite->setLocation(transform->m_location);
    }

    m_sprite->draw();
    m_shader->unbind();
}

#endif //ENGINITO_C_RENDERABLE_H
