//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_SPRITE_H
#define ENGINITO_SPRITE_H

#include "../../../types/Texture.h"
#include "../../../types/Vector.h"

class Sprite {
protected:
    Vector2 m_location;
    Vector2 m_dimensions;
public:
    Sprite(Vector2 location, Vector2 dimensions)
        : m_location(location)
        , m_dimensions(dimensions) {

    }

    virtual ~Sprite() = default;

    void setLocation(Vector2 location) {
        m_location = location;
    }

    void setDimensions(Vector2 dimensions) {
        m_dimensions = dimensions;
    }

    virtual void setTexture(Texture texture) = 0;
    virtual void draw() = 0;

};

#endif //ENGINITO_SPRITE_H
