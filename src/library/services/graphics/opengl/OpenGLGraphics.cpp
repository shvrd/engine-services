//
// Created by thekatze on 25/12/2018.
//

#include <sstream>

#include "OpenGLGraphics.h"
#include "../../../log/Logger.h"
#include "GLSLShader.h"
#include "../../../types/Vertex.h"
#include "OpenGLSprite.h"
#include "util/ImageLoader.h"

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

    m_freeType.initialize();
    m_freeType.useFont("../../../src/library/assets/fonts/OpenSans-Regular.ttf");

    Logger::info("Setting up Camera");

    m_camera = std::make_shared<Camera>(Vector2(static_cast<float>(windowWidth), static_cast<float>(windowHeight)));

    setViewport(windowWidth, windowHeight);
}

std::shared_ptr<Texture> OpenGLGraphics::loadTexture(const std::string &filePath) {
    // If texture is already cached, return it.
    if (auto texture = m_textures.get(filePath)) {
        Logger::info("Loaded texture from cache: " + filePath);
        return texture;
    }

    Logger::info("Loading texture for the first time: " + filePath);

    auto texture = ImageLoader::loadPNG(filePath);

    m_textures.add(filePath, texture);

    return texture;
}

std::shared_ptr<Shader> OpenGLGraphics::createShader() {
    return std::make_shared<GLSLShader>();
}

std::shared_ptr<Sprite> OpenGLGraphics::createSprite(Vector2 location, Vector2 dimensions) {
    return std::make_shared<OpenGLSprite>(location, dimensions);
}

void OpenGLGraphics::setViewport(int width, int height) {
    glViewport(0, 0, width, height);
    m_camera->setScreenDimensions({static_cast<float>(width), static_cast<float>(height)});

    // TODO: Validate this behaviour
    m_camera->setLocation({static_cast<float>(-width) / 2, static_cast<float>(-height) / 2});
}

void OpenGLGraphics::useTexture(std::shared_ptr<Texture> texture) {
    if (!texture || !texture->id) {
        Logger::error("Given texture has not been properly loaded");

        return;
    }

    glActiveTexture(GL_TEXTURE0);

    glUniform1i(m_currentShader->getUniformLocation("image"), 0);
    glBindTexture(GL_TEXTURE_2D, texture->id);
}

void OpenGLGraphics::bindShader(const std::shared_ptr<Shader> shader) {
    Graphics::bindShader(shader);

    glUniformMatrix4fv(m_currentShader->getUniformLocation("projection"), 1, GL_FALSE, &(m_camera->getCameraMatrix()[0][0]));
}

void OpenGLGraphics::drawText(const std::string &text, Vector2 location) {
    for (auto iterator = text.begin(); iterator < text.end(); ++iterator) {
        m_freeType.getLetter(*iterator);
    }

}
