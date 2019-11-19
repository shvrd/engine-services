//
// Created by thekatze on 17/04/2019.
//

#ifndef SHVRD_CAMERA_H
#define SHVRD_CAMERA_H

#include <glm/glm.hpp>

#include "../../types/Vector.h"

class Camera {
    glm::mat4 m_camera;
    Vector2f m_location;
    float m_rotation;
    float m_scale;

    Vector2f m_screen;

    glm::mat4 m_ortho;

    bool m_dirty;

    void update();
public:
    explicit Camera(const Vector2f& screenDimensions);
    ~Camera() = default;

    glm::mat4 getCameraMatrix();

    void setScreenDimensions(const Vector2f& dimensions);

    void translate(const Vector2f& translation);
    void scale(float factor);
    void rotate(float amount);

    void setLocation(const Vector2f& location);
    void setScale(float scale);
    void setRotation(float rotation);

    const Vector2f& getLocation() const;
    const float& getScale() const;
    const float& getRotation() const;
};



#endif //SHVRD_CAMERA_H
