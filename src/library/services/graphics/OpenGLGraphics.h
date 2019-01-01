//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_OPENGLGRAPHICS_H
#define ENGINITO_OPENGLGRAPHICS_H


#include "Graphics.h"

class OpenGLGraphics : public Graphics {
public:
    void clear() override;
    void setClearColor() override;
};


#endif //ENGINITO_OPENGLGRAPHICS_H
