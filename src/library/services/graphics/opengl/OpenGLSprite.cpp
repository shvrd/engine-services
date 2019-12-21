//
// Created by thekatze on 10/02/2019.
//

#include "OpenGLSprite.h"
#include "../../../types/Vertex.h"
#include "../../../log/Logger.h"
#include "../../GraphicsServiceLocator.h"
#include "util/VAOCreator.h"

OpenGLSprite::OpenGLSprite(const Vector2f& offset, const Vector2f& dimensions) : Sprite(offset, dimensions) {
    VAOCreator::createVertexVAOandVBO(m_graphicsId, m_vertexBufferObject);

    updateBuffer();
}

void OpenGLSprite::setTexture(const std::shared_ptr<Texture> texture) {
    Sprite::setTexture(texture);
}

void OpenGLSprite::updateBuffer() {
    // TODO: Use Model/World transformation matrices

    // Bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

    Vertex vertices[VERTEX_AMOUNT];

    // top left, top right, bottom left, bottom right
    vertices[0] = Vertex{{m_location.x,  m_location.y, 0.f}, Colors::WHITE, {0, 1}};
    vertices[1] = Vertex{{m_location.x + m_dimensions.x,  m_location.y, 0.f}, Colors::WHITE, {1, 1}};
    vertices[2] = Vertex{{m_location.x, m_location.y + m_dimensions.y, 0.f}, Colors::WHITE, {0, 0}};
    vertices[3] = Vertex{{m_location.x + m_dimensions.x, m_location.y + m_dimensions.y, 0.f}, Colors::WHITE, {1, 0}};

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
