//
// Created by thekatze on 18/11/2019.
//

#ifndef SHVRD_VAOCREATOR_H
#define SHVRD_VAOCREATOR_H


#include <GL/glew.h>

class VAOCreator {
public:
    static bool createVertexVAOandVBO(GLuint& vao, GLuint& vbo);
};


#endif //SHVRD_VAOCREATOR_H
