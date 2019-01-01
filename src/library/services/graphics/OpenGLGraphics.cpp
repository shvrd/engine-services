//
// Created by thekatze on 25/12/2018.
//

#include "OpenGLGraphics.h"
#include <GL/gl.h>

void OpenGLGraphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphics::setClearColor() {
    glViewport(0, 0, 800, 600);
    glClearColor(0.f, 1.f, 0.f, 0.5f);
}
