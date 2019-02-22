//
// Created by thekatze on 05/01/2019.
//

#ifndef ENGINITO_GLSLSHADER_H
#define ENGINITO_GLSLSHADER_H

#include <GL/glew.h>

#include "../Shader.h"

class GLSLShader : public Shader {
    GLuint m_shaderProgram;

    GLuint m_vertexShaderProgram;
    GLuint m_fragmentShaderProgram;

public:
    GLSLShader();
    ~GLSLShader() override;

    void bind() override;
    void unbind() override;

    void setVertexShader(const std::string& filePath) override;
    void setFragmentShader(const std::string& filePath) override;

    void finalize() override;

    void reload() override;

private:
    //TODO: These could be outsourced into some static shader utils
    static void compileShader(GLuint& id, const std::string& source);
    static void linkProgram(GLuint& programID, GLuint& vertexShaderID, GLuint& fragmentShaderID);
};


#endif //ENGINITO_GLSLSHADER_H
