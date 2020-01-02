//
// Created by thekatze on 17/11/2019.
//

#ifndef SHVRD_C_PLAYERCONTROLLER_H
#define SHVRD_C_PLAYERCONTROLLER_H

#include <memory>

#include <components/Entity.h>
#include <components/Component.h>
#include <services/input/Input.h>
#include <services/InputServiceLocator.h>
#include <services/input/GLFWInput.h>
#include <log/Logger.h>
#include "C_Transform.h"
#include "C_Health.h"

class C_PlayerController : public Component {
    std::shared_ptr<Input> m_input;
    float m_speed = 4.f;
public:
    C_PlayerController(std::shared_ptr<Input> input)
        : m_input(std::move(input)) {}

    void update() override;
};

void C_PlayerController::update() {
    C_Transform* transform = getParent()->getComponent<C_Transform>();
    C_Health* health = getParent()->getComponent<C_Health>();

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

    if (m_input->isKeyPressed(Key::W)) {
        transform->m_location += {0, m_speed};
    }
    if (m_input->isKeyPressed(Key::S)) {
        transform->m_location += {0, -m_speed};
    }
    if (m_input->isKeyPressed(Key::A)) {
        transform->m_location += {-m_speed, 0};
    }
    if (m_input->isKeyPressed(Key::D)) {
        transform->m_location += {m_speed, 0};
    }
}

#endif //SHVRD_C_PLAYERCONTROLLER_H
