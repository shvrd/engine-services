//
// Created by thekatze on 05/01/2019.
//

#include <string>
#include <vector>
#include "GLSLShader.h"
#include "../../../log/Logger.h"

GLSLShader::GLSLShader()
    : m_shaderProgram(0)
    , m_vertexShaderProgram(0)
    , m_fragmentShaderProgram(0) {

}

void GLSLShader::compileShader(GLuint &id, const std::string& source) {
    Logger::info("Compiling shader: " + source);

    char const* shaderSource = source.c_str();
    glShaderSource(id, 1, &shaderSource, nullptr);
    glCompileShader(id);

    int compileStatus = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);

    // Error handling if shader fails to compile
    if (compileStatus != GL_TRUE) {
        Logger::warn("Compilation of shader " + source + " unsuccessful.");

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

    if (vertexShaderID == 0) {
        Logger::error("Vertex shader did not compile, cant link shader program");

        return;
    }

    if (fragmentShaderID == 0) {
        Logger::error("Fragment shader did not compile, cant link shader program");

        return;
    }

    programID = glCreateProgram();

    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void GLSLShader::bind() {
    glUseProgram(m_shaderProgram);
}

GLSLShader::~GLSLShader() {
    glDeleteProgram(m_shaderProgram);
}
