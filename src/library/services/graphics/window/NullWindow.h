//
// Created by thekatze on 24/12/2018.
//

#ifndef SHVRD_NULLWINDOW_H
#define SHVRD_NULLWINDOW_H

#include "Window.h"

class NullWindow : public Window {
public:
    NullWindow() = default;
    ~NullWindow() = default;

    void initialize(unsigned int width, unsigned int height, const std::string& windowTitle) override {}

    void swapBuffers() override {}
    void pollEvents() override {}

    void setTitle(const std::string& title) override {}

    bool windowShouldClose() override { return false; }
};

#endif //SHVRD_NULLWINDOW_H
