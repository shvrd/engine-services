//
// Created by thekatze on 17/11/2019.
//

#ifndef SHVRD_C_TRANSFORM_H
#define SHVRD_C_TRANSFORM_H

#include <components/Component.h>
#include <types/Vector.h>

class C_Transform : public Component {
public:
    // TODO: rotation, scale
    Vector2f m_location;
    float m_rotation;
    float m_scale;

    explicit C_Transform(Vector2f location = {}, float rotation = 0.f, float scale = 1.f)
        : m_location(location)
        , m_rotation(rotation)
        , m_scale(scale) {}
};

#endif //SHVRD_C_TRANSFORM_H
