//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_SPRITE_H
#define ENGINITO_SPRITE_H

#include <memory>

#include "../../resources/Texture.h"
#include "../../types/Vector.h"

class Sprite {
protected:
    Vector2f m_location;
    Vector2f m_dimensions;

    std::shared_ptr<Texture> m_texture;

    virtual void updateBuffer() = 0;
public:
    Sprite(const Vector2f& location, const Vector2f& dimensions)
        : m_location(location)
        , m_dimensions(dimensions) {

    }

    virtual ~Sprite() = default;

    virtual void setLocation(const Vector2f& location) {
        m_location = location;
        updateBuffer();
    }

    virtual void setDimensions(const Vector2f& dimensions) {
        m_dimensions = dimensions;
        updateBuffer();
    }

    Vector2f getLocation() const {
        return m_location;
    }

    Vector2f getDimensions() const {
        return m_dimensions;
    }

    std::shared_ptr<Texture> getTexture() const {
        return m_texture;
    }

    void translate(const Vector2f &translation) {
        m_location = m_location + translation;
        updateBuffer();
    }

    virtual void setTexture(std::shared_ptr<Texture> texture) {
        m_texture = texture;
    }

    virtual void draw() const = 0;

};

#endif //ENGINITO_SPRITE_H
