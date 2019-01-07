//
// Created by thekatze on 25/12/2018.
//

#include "OpenGLGraphics.h"
#include "../../../log/Logger.h"
#include "GLSLShader.h"

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
