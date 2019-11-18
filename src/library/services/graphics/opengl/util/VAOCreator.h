//
// Created by thekatze on 18/11/2019.
//

#ifndef ENGINITO_VAOCREATOR_H
#define ENGINITO_VAOCREATOR_H


#include <GL/glew.h>

class VAOCreator {
public:
    static bool createVertexVAOandVBO(GLuint& vao, GLuint& vbo);
};


#endif //ENGINITO_VAOCREATOR_H
