//
// Created by thekatze on 17/11/2019.
//

#ifndef ENGINITO_C_PLAYERCONTROLLER_H
#define ENGINITO_C_PLAYERCONTROLLER_H

#include <memory>

#include <components/Entity.h>
#include <components/Component.h>
#include <services/input/Input.h>
#include <services/InputServiceLocator.h>
#include <services/input/GLFWInput.h>
#include "C_Transform.h"

class C_PlayerController : public Component {
    std::shared_ptr<Input> m_input;
public:
    C_PlayerController(std::shared_ptr<Input> input)
        : m_input(std::move(input)) {}

    void update() override;
    void render() override;
};

void C_PlayerController::update() {
    C_Transform* transform = getParent()->getComponent<C_Transform>();

    if (m_input->isKeyPressed(Key::W)) {
        transform->m_location += {0, 1};
    }
    if (m_input->isKeyPressed(Key::S)) {
        transform->m_location += {0, -1};
    }
    if (m_input->isKeyPressed(Key::A)) {
        transform->m_location += {-1, 0};
    }
    if (m_input->isKeyPressed(Key::D)) {
        transform->m_location += {1, 0};
    }
}

void C_PlayerController::render() {

}

#endif //ENGINITO_C_PLAYERCONTROLLER_H
