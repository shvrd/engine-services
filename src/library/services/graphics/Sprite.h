//
// Created by thekatze on 10/02/2019.
//

#ifndef SHVRD_SPRITE_H
#define SHVRD_SPRITE_H

#include <memory>

#include "../../resources/Texture.h"
#include "../../types/Vector.h"

class Sprite {
protected:
    unsigned int m_graphicsId;

    Vector2f m_location;
    Vector2f m_dimensions;
    Vector2f m_offset;

    float m_rotation;
    float m_scale;

    std::shared_ptr<Texture> m_texture;

    virtual void updateBuffer() = 0;
public:
    Sprite(const Vector2f& offset, const Vector2f& dimensions)
        : m_graphicsId(0)
        , m_location()
        , m_dimensions(dimensions)
        , m_offset(offset)
        , m_rotation(0.f)
        , m_scale(1.f) {

    }

    virtual ~Sprite() = default;

    virtual void setLocation(const Vector2f& location) {
        m_location = location + m_offset;
        updateBuffer();
    }

    virtual void setDimensions(const Vector2f& dimensions) {
        m_dimensions = dimensions;
        updateBuffer();
    }

    virtual void setRotation(const float rotation) {
        m_rotation = rotation;
        updateBuffer();
    }

    virtual void setScale(const float scale) {
        m_scale = scale;
        updateBuffer();
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
        updateBuffer();
    }

    void rotate(const float rotation) {
        m_rotation += rotation;
        updateBuffer();
    }

    void scale(const float scaleFactor) {
        m_scale *= scaleFactor;
        updateBuffer();
    }

    virtual void setTexture(std::shared_ptr<Texture> texture) {
        m_texture = std::move(texture);
    }

    unsigned int getGraphicsIdentifier() {
        return m_graphicsId;
    }

    void setGraphicsIdentifier(unsigned int graphicsId) {
        m_graphicsId = graphicsId;
    }
};

#endif //SHVRD_SPRITE_H
