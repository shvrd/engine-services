//
// Created by thekatze on 24/12/2018.
//

#ifndef ENGINITO_GLFWINPUT_H
#define ENGINITO_GLFWINPUT_H

#include <GLFW/glfw3.h>
#include "Input.h"
#include "../graphics/window/Window.h"

class GLFWInput : public Input {
    GLFWwindow* m_window;

    int m_mouseX, m_mouseY;
    int m_deltaMouseX, m_deltaMouseY;
public:
    GLFWInput() = default;
    ~GLFWInput() override = default;

    void update() override;

    bool isKeyPressed(Key key) override;
    bool isKeyReleased(Key key) override;

    int getMouseX() override;
    int getMouseY() override;

    int getDeltaMouseX() override;
    int getDeltaMouseY() override;

    void setGLFWWindow(Window* window);
};


#endif //ENGINITO_GLFWINPUT_H
