//
// Created by thekatze on 10/02/2019.
//

#include "OpenGLSprite.h"
#include "../../../../types/Vertex.h"


void OpenGLSprite::draw() {

    Vertex vertices[VERTEX_AMOUNT];

    // top left, top right, bottom left, bottom right
    vertices[0] = Vertex{{-.25f,  .25f, 0.f}, {255, 0  , 0  }, {0, 0}};
    vertices[1] = Vertex{{ .25f,  .25f, 0.f}, {0  , 255, 0  }, {0, 0}};
    vertices[2] = Vertex{{ .25f, -.25f, 0.f}, {0  , 0  , 255}, {0, 0}};
    vertices[3] = Vertex{{-.25f, -.25f, 0.f}, {127, 0  , 127}, {0, 0}};

    // Bind vertex array object
    glBindVertexArray(m_vertexArrayObject);

    // Bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Vertex Attribute ID 0: Position
    glVertexAttribPointer((GLuint) 0, sizeof(Vector3), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));

    // Vertex Attribute ID 1: Color
    glVertexAttribPointer(1, sizeof(Color), GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));

    // Vertex Attribute ID 2: UV Map
    glVertexAttribPointer(2, sizeof(Vector2), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, uv));

    glBindVertexArray(0);

    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, VERTEX_AMOUNT);
    glBindVertexArray(0);
}

void OpenGLSprite::setTexture(Texture texture) {

}
