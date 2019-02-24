//
// Created by thekatze on 25/12/2018.
//

#include <sstream>

#include "OpenGLGraphics.h"
#include "../../../log/Logger.h"
#include "GLSLShader.h"
#include "../../../types/Vertex.h"
#include "OpenGLSprite.h"

OpenGLGraphics::OpenGLGraphics()
    : m_vertexArrayObject(0)
    , m_vertexBufferObject(0) {

}

void OpenGLGraphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphics::setClearColor() {
    glClearColor(0.1f, 0.1f, 0.4f, 1.f);
}

void GLAPIENTRY
MessageCallback(GLenum source,
                GLenum type,
                GLuint id,
                GLenum severity,
                GLsizei length,
                const GLchar *message,
                const void *userParam) {
    std::stringstream log;

    log << message << " | Type: 0x" << type;

    if (severity == GL_DEBUG_TYPE_ERROR) {
        Logger::error(log.str());
    } else {
        Logger::info(log.str());
    }
}

void OpenGLGraphics::initialize(int windowWidth, int windowHeight) {
    glewExperimental = GL_TRUE;
    GLenum initStatus = glewInit();

    if(initStatus != GLEW_OK) {
        Logger::error((char*)glewGetErrorString(initStatus));

        Logger::critical("GLEW/GL could not be initialized", -5);
    }

    Logger::info(std::string("OpenGL Version: ") + (char*)(glGetString(GL_VERSION)));

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, nullptr);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    glGenVertexArrays(1, &m_vertexArrayObject);

    glBindVertexArray(m_vertexArrayObject);
    glGenBuffers(1, &m_vertexBufferObject);
    glBindVertexArray(0);

    glViewport(0, 0, windowWidth, windowHeight);
}

std::unique_ptr<Shader> OpenGLGraphics::createShader() {
    return std::make_unique<GLSLShader>();
}

std::unique_ptr<Sprite> OpenGLGraphics::createSprite(Vector2 location, Vector2 dimensions) {
    return std::make_unique<OpenGLSprite>(location, dimensions);
}
