//
// Created by thekatze on 17/04/2019.
//

#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const Vector2f &screenDimensions)
    : m_camera()
    , m_location({0.f,0.f})
    , m_rotation(0.f)
    , m_scale(1.f)
    , m_screen(screenDimensions)
    , m_ortho()
    , m_dirty(true) {
    setScreenDimensions(screenDimensions);

    translate({-screenDimensions.x / 2, -screenDimensions.y / 2});

    update();
}

glm::mat4 Camera::getCameraMatrix() {
    if (m_dirty) {
        update();
    }

    return m_camera;
}

void Camera::update() {
    m_camera = m_ortho;

    // Translate
    m_camera = glm::translate(m_camera, glm::vec3(-m_location.x, -m_location.y, 0.f));

    // Rotate
    m_camera = glm::rotate(m_camera, glm::radians(m_rotation), glm::vec3(0.f, 0.f, 1.f));

    // Scale
    m_camera = glm::scale(m_camera, glm::vec3(m_scale, m_scale, 0.f));

    m_dirty = false;
}

void Camera::setScreenDimensions(const Vector2f &dimensions) {
    m_screen = dimensions;

    m_ortho = glm::ortho(0.f, m_screen.x, 0.f, m_screen.y);

    m_dirty = true;
}

void Camera::translate(const Vector2f &translation) {
    setLocation({m_location.x + translation.x, m_location.y + translation.y});
}

void Camera::scale(const float factor) {
    setScale(m_scale * factor);
}

void Camera::rotate(float amount) {
    setRotation(m_rotation + amount);
}

void Camera::setLocation(const Vector2f &location) {
    m_location = location;
    m_dirty = true;
}

void Camera::setScale(const float scale) {
    m_scale = scale;
    m_dirty = true;
}

void Camera::setRotation(const float rotation) {
    m_rotation = rotation;
    m_dirty = true;
}

const Vector2f &Camera::getLocation() const {
    return m_location;
}

const float &Camera::getScale() const {
    return m_scale;
}

const float &Camera::getRotation() const {
    return m_rotation;
}
