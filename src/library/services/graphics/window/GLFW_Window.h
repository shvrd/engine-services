//
// Created by thekatze on 23/12/2018.
//

#ifndef SHVRD_GLFWWINDOW_H
#define SHVRD_GLFWWINDOW_H

#include "Window.h"

#include <GLFW/glfw3.h>
#include <memory>

class GLFW_Window : public Window {
    GLFWwindow* m_window;

public:
    void initialize(unsigned int width, unsigned int height, const std::string& windowTitle) override;

    void swapBuffers() override;
    void pollEvents() override;

    bool shouldClose() override;

    void setTitle(const std::string& title) override;

    ~GLFW_Window() override;

    GLFWwindow* getWindow();
};


#endif //SHVRD_GLFWWINDOW_H
