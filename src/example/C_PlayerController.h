//
// Created by thekatze on 17/11/2019.
//

#ifndef SHVRD_C_PLAYERCONTROLLER_H
#define SHVRD_C_PLAYERCONTROLLER_H

#include <memory>

#include <components/Entity.h>
#include <components/Component.h>
#include <components/generic/C_Health.h>
#include <services/input/Input.h>
#include <services/InputServiceLocator.h>
#include <services/input/GLFWInput.h>
#include <log/Logger.h>

class C_PlayerController : public Component {
    std::shared_ptr<Input> m_input;
    float m_speed = 4.f;

    std::shared_ptr<Sound> m_select;

    enum Direction {
        UP, DOWN, LEFT, RIGHT
    } m_direction;

public:
    C_PlayerController(std::shared_ptr<Input> input)
        : m_input(std::move(input))
        , m_select(AudioServiceLocator::get()->loadSound("assets/sounds/select.ogg")) {
    }

    void update() override;
};

void C_PlayerController::update() {
    C_Transform* transform = getParent()->getComponent<C_Transform>();
    C_Health* health = getParent()->getComponent<C_Health>();
    C_SoundSource* soundSource = getParent()->getComponent<C_SoundSource>();

    if (health) {
        if (m_input->isKeyPressed(Key::ZERO)) {
            health->applyDamage(1);

            Logger::info("Health: " + std::to_string(health->getHealth()));
        }

        if (health->isDead()) {
            return;
        }
    }

    if (!transform) {
        return;
    }

    if (m_input->isKeyDown(Key::W)) {
        transform->m_location += {0, m_speed};
        m_direction = Direction::UP;
    }

    if (m_input->isKeyDown(Key::S)) {
        transform->m_location += {0, -m_speed};
        m_direction = Direction::DOWN;
    }

    if (m_input->isKeyDown(Key::A)) {
        transform->m_location += {-m_speed, 0};
        m_direction = Direction::LEFT;
    }

    if (m_input->isKeyDown(Key::D)) {
        transform->m_location += {m_speed, 0};
        m_direction = Direction::RIGHT;
    }

    if (m_input->isKeyPressed(Key::P)) {
        AudioServiceLocator::get()->playSound(m_select, soundSource->getSource());
    }
}

#endif //SHVRD_C_PLAYERCONTROLLER_H
