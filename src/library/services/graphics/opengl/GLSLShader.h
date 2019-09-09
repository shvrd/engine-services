//
// Created by thekatze on 05/01/2019.
//

#ifndef ENGINITO_GLSLSHADER_H
#define ENGINITO_GLSLSHADER_H

#include <GL/glew.h>

#include "../Shader.h"
#include "OpenGLSprite.h"

class GLSLShader : public Shader {
    GLuint m_shaderProgram;

    GLuint m_vertexShaderProgram;
    GLuint m_fragmentShaderProgram;

    std::string m_vertexShaderPath;
    std::string m_fragmentShaderPath;

public:
    GLSLShader();
    ~GLSLShader() override;

    void bind() override;
    void unbind() override;

    void setVertexShader(const std::string& filePath) override;
    void setFragmentShader(const std::string& filePath) override;

    void finalize() override;

    void reload() override;

    void addAttribute(const std::string& attributeName) override;

    void use() override;
    void endUse() override;

private:
    void cleanUp();

    //TODO: These could be outsourced into some static shader utils
    static void compileShader(GLuint& id, const std::string& source);
    static void linkProgram(GLuint& programID, GLuint& vertexShaderID, GLuint& fragmentShaderID);

    int getUniformLocation(const std::string& uniformName);
};


#endif //ENGINITO_GLSLSHADER_H
