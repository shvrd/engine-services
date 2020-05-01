//
// Created by thekatze on 29/12/2019.
//

#ifndef SHVRD_C_CAMERA_H
#define SHVRD_C_CAMERA_H

#include <memory>

#include "../Component.h"
#include "../Entity.h"
#include "../../services/GraphicsServiceLocator.h"

#include "C_Transform.h"

class C_Camera : public Component {

public:
    C_Camera() = default;
    ~C_Camera() = default;

    void update() override;
};

void C_Camera::update() {
    C_Transform* transform = getParent()->getComponent<C_Transform>();

    if (transform) {
        std::shared_ptr<Camera> camera = GraphicsServiceLocator::get()->getCamera();

        camera->setLocation(transform->m_location);
        camera->setRotation(transform->m_rotation);
        camera->setScale(transform->m_scale);
    }
}

#endif //SHVRD_C_CAMERA_H
