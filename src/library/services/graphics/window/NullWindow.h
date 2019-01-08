//
// Created by thekatze on 24/12/2018.
//

#ifndef ENGINITO_NULLWINDOW_H
#define ENGINITO_NULLWINDOW_H

#include "Window.h"

class NullWindow : public Window {
public:
    NullWindow() = default;
    ~NullWindow() = default;

    virtual void initialize(unsigned int width, unsigned int height, const std::string& windowTitle) override {}

    virtual void swapBuffers() override {}
    virtual void pollEvents() override {}

    virtual bool windowShouldClose() override { return false; }
};

#endif //ENGINITO_NULLWINDOW_H
