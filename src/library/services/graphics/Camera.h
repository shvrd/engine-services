//
// Created by thekatze on 17/04/2019.
//

#ifndef ENGINITO_CAMERA_H
#define ENGINITO_CAMERA_H

#include <glm/glm.hpp>

#include "../../types/Vector.h"

class Camera {
    Vector2 m_location;

    glm::mat4 m_ortho;
    glm::mat4 m_camera;

    Vector2 m_screen;

    float m_scale;
    float m_rotation;

    bool m_dirty;

    void update();
public:
    glm::mat4 getCameraMatrix();

    void setScreenDimensions(const Vector2& dimensions);

    void translate(const Vector2& translation);
    void scale(float factor);
    void rotate(float amount);

    void setLocation(const Vector2& location);
    void setScale(float scale);
    void setRotation(float rotation);

    const Vector2& getLocation() const;
    const float& getScale() const;
    const float& getRotation() const;
};



#endif //ENGINITO_CAMERA_H
