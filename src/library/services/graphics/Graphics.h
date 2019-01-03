//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_GRAPHICS_H
#define ENGINITO_GRAPHICS_H

class Graphics {
public:
    virtual void clear() = 0;
    virtual void setClearColor() = 0;

    virtual void initialize(int windowWidth, int windowHeight) = 0;
};

#endif //ENGINITO_GRAPHICS_H
