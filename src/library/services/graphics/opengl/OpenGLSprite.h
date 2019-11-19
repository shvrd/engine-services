//
// Created by thekatze on 10/02/2019.
//

#ifndef SHVRD_OPENGLSPRITE_H
#define SHVRD_OPENGLSPRITE_H

#include "../Sprite.h"

#include <GL/glew.h>

class OpenGLSprite : public Sprite {
    const unsigned int VERTEX_AMOUNT = 4;
    GLuint m_vertexBufferObject;

public:
    OpenGLSprite(const Vector2f& location, const Vector2f& dimensions);

    ~OpenGLSprite() override = default;

    void setTexture(const std::shared_ptr<Texture> texture) override;
private:
    void updateBuffer() override;
};


#endif //SHVRD_OPENGLSPRITE_H
