//
// Created by thekatze on 10/02/2019.
//

#include "OpenGLSprite.h"
#include "../../../types/Vertex.h"
#include "../../../log/Logger.h"

OpenGLSprite::OpenGLSprite(const Vector2& location, const Vector2& dimensions) : Sprite(location, dimensions) {

    glGenVertexArrays(1, &m_vertexArrayObject);

    glGenBuffers(1, &m_vertexBufferObject);

    // Bind vertex array object
    glBindVertexArray(m_vertexArrayObject);

    // Bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

    // Vertex Attribute ID 0: Position
    glVertexAttribPointer((GLuint) 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));

    // Vertex Attribute ID 1: Color
    glVertexAttribPointer((GLuint) 1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));

    // Vertex Attribute ID 2: UV Map
    glVertexAttribPointer((GLuint) 2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, uv));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    updateBuffer();
}

void OpenGLSprite::draw() {
    glBindVertexArray(m_vertexArrayObject);

    // Move to shader bind
    for (int i = 0; i <= 2; ++i)  {
        glEnableVertexAttribArray(i);
    }

    glDrawArrays(GL_TRIANGLE_STRIP, 0, VERTEX_AMOUNT);

    // Move to shader unbind
    for (int i = 0; i <= 2; ++i)  {
        glDisableVertexAttribArray(i);
    }

    glBindVertexArray(0);
}

void OpenGLSprite::setTexture(const Texture& texture) {

}

void OpenGLSprite::updateBuffer() {
    // Bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

    Vertex vertices[VERTEX_AMOUNT];

    // top left, top right, bottom left, bottom right
    vertices[0] = Vertex{{m_location.x,  m_location.y, 0.f}, Colors::WHITE, {0, 1}};
    vertices[1] = Vertex{{m_location.x + m_dimensions.x,  m_location.y, 0.f}, Colors::WHITE, {1, 1}};
    vertices[2] = Vertex{{m_location.x, m_location.y + m_dimensions.y, 0.f}, Colors::WHITE, {1, 0}};
    vertices[3] = Vertex{{m_location.x + m_dimensions.x, m_location.y + m_dimensions.y, 0.f}, Colors::WHITE, {0, 0}};

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLSprite::setLocation(const Vector2& location) {
    Sprite::setLocation(location);
    updateBuffer();
}

void OpenGLSprite::setDimensions(const Vector2& dimensions) {
    Sprite::setDimensions(dimensions);
    updateBuffer();
}

void OpenGLSprite::translate(const Vector2& translation) {
    setLocation({m_location.x + translation.x, m_location.y + translation.y});
}

