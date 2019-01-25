//
// Created by thekatze on 25/12/2018.
//

#include "OpenGLGraphics.h"
#include "../../../log/Logger.h"
#include "GLSLShader.h"
#include "../../../../types/Vertex.h"

OpenGLGraphics::OpenGLGraphics() : m_vertexArrayObject(0) {

}

void OpenGLGraphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphics::setClearColor() {
    glClearColor(0.1f, 0.1f, 0.4f, 1.f);
}

void OpenGLGraphics::initialize(int windowWidth, int windowHeight) {
    glewExperimental = GL_TRUE;
    GLenum initStatus = glewInit();

    if(initStatus != GLEW_OK) {
        Logger::error((char*)glewGetErrorString(initStatus));

        Logger::critical("GLEW/GL could not be initialized", -5);
    }

    Logger::info(std::string("OpenGL Version: ") + (char*)(glGetString(GL_VERSION)));

    glGenVertexArrays(1, &m_vertexArrayObject);
    glViewport(0, 0, windowWidth, windowHeight);
}

std::unique_ptr<Shader> OpenGLGraphics::createShader() {
    return std::make_unique<GLSLShader>();
}

void OpenGLGraphics::drawSquare() {
    const unsigned int VERTEX_AMOUNT = 4;
    Vertex vertices[VERTEX_AMOUNT];

    // top left, top right, bottom left, bottom right
    vertices[0] = Vertex{{-.25f,  .25f, 0.f}, {0, 0, 0}, {0, 0}};
    vertices[1] = Vertex{{ .25f,  .25f, 0.f}, {0, 0, 0}, {0, 0}};
    vertices[2] = Vertex{{ .25f, -.25f, 0.f}, {0, 0, 0}, {0, 0}};
    vertices[3] = Vertex{{-.25f, -.25f, 0.f}, {0, 0, 0}, {0, 0}};

    // Generate vertex buffer object
    GLuint vboID = 0;
    glGenBuffers(1, &vboID);

    glBindBuffer(GL_ARRAY_BUFFER, vboID);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex Attribute ID 0: Position
    glVertexAttribPointer(0, sizeof(Vector3), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));

    // Vertex Attribute ID 1: Color
    glVertexAttribPointer(1, sizeof(Color), GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));

    // Vertex Attribute ID 2: UV Map
    glVertexAttribPointer(2, sizeof(Vector2), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, uv));

    for (int i = 0; i < 2; ++i) {
        glEnableVertexAttribArray(i);
    }

    glDrawArrays(GL_TRIANGLE_STRIP, 0, VERTEX_AMOUNT);

    for (int i = 0; i < 2; ++i) {
        glDisableVertexAttribArray(i);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
