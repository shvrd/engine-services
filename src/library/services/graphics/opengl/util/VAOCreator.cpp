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

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return false;
}
