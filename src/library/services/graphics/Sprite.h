//
// Created by thekatze on 10/02/2019.
//

#ifndef SHVRD_SPRITE_H
#define SHVRD_SPRITE_H

#include <memory>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "../../resources/Texture.h"
#include "../../types/Vector.h"

class Sprite {
    Vector2f m_location;
    Vector2f m_dimensions;
    Vector2f m_offset;

    float m_rotation;
    float m_scale;

    glm::mat4 m_model;

    std::shared_ptr<Texture> m_texture;

    bool m_dirty;

    void updateMatrix() {
        m_model = glm::mat4(1.f);

        // Translate
        m_model = glm::translate(m_model, glm::vec3(m_location.x, m_location.y, 0.f));

        // Rotate
        m_model = glm::rotate(m_model, glm::radians(m_rotation), glm::vec3(0.f, 0.f, 1.f));

        // Scale
        m_model = glm::scale(m_model, glm::vec3(m_dimensions.x * m_scale, m_dimensions.y * m_scale, 0.f));
    }

public:
    Sprite(const Vector2f& offset, const Vector2f& dimensions)
        : m_location(offset)
        , m_dimensions(dimensions)
        , m_offset(offset)
        , m_rotation(0.f)
        , m_scale(1.f)
        , m_model(1.f)
        , m_dirty(true) {
    }

    ~Sprite() = default;

    void setLocation(const Vector2f& location) {
        m_location = location + m_offset;
        m_dirty = true;
    }

    void setDimensions(const Vector2f& dimensions) {
        m_dimensions = dimensions;
        m_dirty = true;
    }

    void setRotation(const float rotation) {
        m_rotation = rotation;
        m_dirty = true;
    }

    void setScale(const float scale) {
        m_scale = scale;
        m_dirty = true;
    }

    Vector2f getLocation() const {
        return m_location;
    }

    Vector2f getDimensions() const {
        return m_dimensions;
    }

    float getRotation() const {
        return m_rotation;
    }

    float getScale() const {
        return m_scale;
    }

    std::shared_ptr<Texture> getTexture() const {
        return m_texture;
    }

    void translate(const Vector2f &translation) {
        m_location += translation;
        m_dirty = true;
    }

    void rotate(const float rotation) {
        m_rotation += rotation;
        m_dirty = true;
    }

    void scale(const float scaleFactor) {
        m_scale *= scaleFactor;
        m_dirty = true;
    }

    void setTexture(std::shared_ptr<Texture> texture) {
        m_texture = std::move(texture);
    }

    float* getModelMatrix() {
        if (m_dirty) {
            updateMatrix();
            m_dirty = false;
        }

        return &m_model[0][0];
    }
};

#endif //SHVRD_SPRITE_H
