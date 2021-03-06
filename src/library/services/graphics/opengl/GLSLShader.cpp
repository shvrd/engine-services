//
// Created by thekatze on 05/01/2019.
//

#include <string>
#include <vector>
#include "GLSLShader.h"
#include "../../../log/Logger.h"
#include "../../../util/FileUtils.h"

GLSLShader::GLSLShader()
    : m_shaderProgram(glCreateProgram())
    , m_vertexShaderProgram(0)
    , m_fragmentShaderProgram(0)
    , m_vertexShaderPath()
    , m_fragmentShaderPath() {

}

void GLSLShader::setVertexShader(const std::string &filePath) {
    m_vertexShaderPath = filePath;

    if (m_vertexShaderProgram != 0) {
        Logger::warn("Shader already created, deleting old shader");

        glDeleteShader(m_vertexShaderProgram);
    }

    m_vertexShaderProgram = glCreateShader(GL_VERTEX_SHADER);

    Logger::info("Compiling Vertex Shader: " + filePath);
    compileShader(m_vertexShaderProgram, FileUtils::readTextFile(filePath));
}

void GLSLShader::setFragmentShader(const std::string &filePath) {
    m_fragmentShaderPath = filePath;

    if (m_fragmentShaderProgram != 0) {
        Logger::warn("Shader already created, deleting old shader");

        glDeleteShader(m_fragmentShaderProgram);
    }

    m_fragmentShaderProgram = glCreateShader(GL_FRAGMENT_SHADER);

    Logger::info("Compiling Fragment Shader: " + filePath);
    compileShader(m_fragmentShaderProgram, FileUtils::readTextFile(filePath));
}

void GLSLShader::compileShader(GLuint &id, const std::string& source) {
    if (id == 0) {
        Logger::error("Shader could not be created.");

        return;
    }

    char const* shaderSource = source.c_str();

    glShaderSource(id, 1, &shaderSource, nullptr);
    glCompileShader(id);

    int compileStatus = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);

    // Error handling if shader fails to compile
    if (compileStatus != GL_TRUE) {
        Logger::warn("Compilation of shader unsuccessful.");

        // Get error message length
        int infoLogLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0) {
            // Read error message
            std::vector<char> errorMessage(static_cast<unsigned int>(infoLogLength + 1));
            glGetShaderInfoLog(id, infoLogLength, nullptr, &errorMessage[0]);

            Logger::warn(std::string(&errorMessage[0]));
        }

        // Delete shader if compilation was unsuccessful
        glDeleteShader(id);
    }
}

void GLSLShader::linkProgram(GLuint& programID, GLuint& vertexShaderID, GLuint& fragmentShaderID) {
    Logger::info("Linking shader program");

    if (programID == 0) {
        Logger::error("Program could not be generated");

        return;
    }

    if (vertexShaderID == 0) {
        Logger::error("Vertex shader did not compile, cant link shader program");

        return;
    }

    if (fragmentShaderID == 0) {
        Logger::error("Fragment shader did not compile, cant link shader program");

        return;
    }

    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    glLinkProgram(programID);

    GLint linked = GL_FALSE;
    glGetProgramiv(programID, GL_LINK_STATUS, &linked);

    if (linked != GL_TRUE) {
        Logger::error("Linking of shaderprogram unsuccessful");

        // Get error message length
        int infoLogLength = 0;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0) {
            // Read error message
            std::vector<char> errorMessage(static_cast<unsigned int>(infoLogLength + 1));
            glGetProgramInfoLog(programID, infoLogLength, nullptr, &errorMessage[0]);

            Logger::warn(std::string(&errorMessage[0]));
        }
    }

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    vertexShaderID = 0;
    glDeleteShader(fragmentShaderID);
    fragmentShaderID = 0;
}

void GLSLShader::bind() {
#ifndef NDEBUG
    if (!m_isFinalized) {
        Logger::error("Binding a shader in non-finalized state leads to undefined behavior.");
    }
#endif
    glUseProgram(m_shaderProgram);
}

void GLSLShader::unbind() {
    glUseProgram(0);
}

GLSLShader::~GLSLShader() {
    cleanUp();
}

void GLSLShader::finalize() {
    linkProgram(m_shaderProgram, m_vertexShaderProgram, m_fragmentShaderProgram);

    m_isFinalized = true;
}

void GLSLShader::reload() {
    // Free resources used by old shader
    this->cleanUp();

    m_shaderProgram = glCreateProgram();

    // Create new shader
    this->setVertexShader(m_vertexShaderPath);
    this->setFragmentShader(m_fragmentShaderPath);

    this->finalize();
}

void GLSLShader::cleanUp() {
    unbind();
    glDeleteProgram(m_shaderProgram);
    m_shaderProgram = 0;
}

int GLSLShader::getUniformLocation(const std::string &uniformName) {
    GLint location = glGetUniformLocation(m_shaderProgram, uniformName.c_str());

    if ((unsigned) location == GL_INVALID_INDEX) {
        Logger::warn("Uniform " + uniformName + " not found in shader!");
    }

    return location;
}

void GLSLShader::addAttribute(const std::string &attributeName) {
    glBindAttribLocation(m_shaderProgram, m_attributes++, attributeName.c_str());
}

void GLSLShader::use() {
    for (GLuint i = 0; i < m_attributes; ++i)  {
        glEnableVertexAttribArray(i);
    }
}

void GLSLShader::endUse() {
    for (GLuint i = 0; i < m_attributes; ++i)  {
        glDisableVertexAttribArray(i);
    }
}
