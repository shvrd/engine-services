//
// Created by thekatze on 18/11/2019.
//

#include "VAOCreator.h"
#include "../../../../types/Vertex.h"

bool VAOCreator::createVertexVAOandVBO(GLuint &vao, GLuint &vbo) {
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Vertex Attribute ID 0: Position
    glVertexAttribPointer((GLuint) 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));

    // Vertex Attribute ID 1: Color
    glVertexAttribPointer((GLuint) 1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));

    // Vertex Attribute ID 2: UV Map
    glVertexAttribPointer((GLuint) 2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, uv));

    // Set default vertices
    Vertex vertices[4];
    // top left, top right, bottom left, bottom right
    vertices[0] = Vertex{{0.f, 1.f, 0.f}, Colors::WHITE, {0, 0}};
    vertices[1] = Vertex{{1.f, 1.f, 0.f}, Colors::WHITE, {1, 0}};
    vertices[2] = Vertex{{0.f, 0.f, 0.f}, Colors::WHITE, {0, 1}};
    vertices[3] = Vertex{{1.f, 0.f, 0.f}, Colors::WHITE, {1, 1}};

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return false;
}
