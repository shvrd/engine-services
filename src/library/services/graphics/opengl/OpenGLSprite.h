//
// Created by thekatze on 10/02/2019.
//

#ifndef ENGINITO_OPENGLSPRITE_H
#define ENGINITO_OPENGLSPRITE_H

#include "../Sprite.h"

#include <GL/glew.h>

class OpenGLSprite : public Sprite {
    const unsigned int VERTEX_AMOUNT = 4;
    GLuint m_vertexArrayObject, m_vertexBufferObject;

public:
    OpenGLSprite(const Vector2& location, const Vector2& dimensions);

    ~OpenGLSprite() override = default;

    void setTexture(const Texture& texture) override;
    void draw() const override;

private:
    void updateBuffer() override;
};


#endif //ENGINITO_OPENGLSPRITE_H
