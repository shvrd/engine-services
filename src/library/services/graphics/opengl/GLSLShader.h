//
// Created by thekatze on 05/01/2019.
//

#ifndef ENGINITO_GLSLSHADER_H
#define ENGINITO_GLSLSHADER_H

#include <GL/glew.h>

class GLSLShader {
    GLuint m_shaderProgram;

public:
    GLSLShader();
    ~GLSLShader() = default;

    GLuint getShaderProgramID() {
        return m_shaderProgram;
    }
};


#endif //ENGINITO_GLSLSHADER_H
