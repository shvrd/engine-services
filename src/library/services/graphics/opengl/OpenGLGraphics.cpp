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

void OpenGLGraphics::setClearColor(Color color) {
    glClearColor(color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
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

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &m_vertexArrayObject);

    glBindVertexArray(m_vertexArrayObject);
    glGenBuffers(1, &m_vertexBufferObject);
    glBindVertexArray(0);

    setViewport(windowWidth, windowHeight);
}

std::shared_ptr<Texture> OpenGLGraphics::loadTexture(const std::string &filePath) {
    std::shared_ptr<Texture> texture = m_textures.get(filePath);

    // If texture has not been loaded yet
    if (!texture) {

    }

    return std::shared_ptr<Texture>();
}

std::unique_ptr<Shader> OpenGLGraphics::createShader() {
    return std::make_unique<GLSLShader>();
}

std::unique_ptr<Sprite> OpenGLGraphics::createSprite(Vector2 location, Vector2 dimensions) {
    return std::make_unique<OpenGLSprite>(location, dimensions);
}

void OpenGLGraphics::setViewport(int width, int height) {
    glViewport(0, 0, width, height);
}
