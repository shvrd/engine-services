//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_OPENGLGRAPHICS_H
#define ENGINITO_OPENGLGRAPHICS_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "../Graphics.h"

class OpenGLGraphics : public Graphics {
    GLuint m_vertexArrayObject, m_vertexBufferObject;
public:
    OpenGLGraphics();
    ~OpenGLGraphics() override = default;

    void clear() override;
    void setClearColor() override;

    void initialize(int windowWidth, int windowHeight) override;

    std::unique_ptr<Shader> createShader() override;
};


#endif //ENGINITO_OPENGLGRAPHICS_H
