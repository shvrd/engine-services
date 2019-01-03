//
// Created by thekatze on 24/12/2018.
//

#include "GLFWInput.h"
#include "../../log/Logger.h"
#include "../graphics/window/GLFW_Window.h"

void GLFWInput::update() {
    int mouseXOld = m_mouseX;
    int mouseYOld = m_mouseY;

    double x, y;
    glfwGetCursorPos(m_window, &x, &y);

    m_mouseX = static_cast<int>(x);
    m_mouseY = static_cast<int>(y);

    m_deltaMouseX = m_mouseX - mouseXOld;
    m_deltaMouseY = m_mouseY - mouseYOld;
}

bool GLFWInput::isKeyPressed(Key key) {
    return glfwGetKey(m_window, static_cast<int>(key)) == GLFW_PRESS;
}

bool GLFWInput::isKeyReleased(Key key) {
    return glfwGetKey(m_window, static_cast<int>(key)) == GLFW_RELEASE;
}

int GLFWInput::getMouseX() {
    return m_mouseX;
}

int GLFWInput::getMouseY() {
    return m_mouseY;
}

int GLFWInput::getDeltaMouseX() {
    return m_deltaMouseX;
}

int GLFWInput::getDeltaMouseY() {
    return m_deltaMouseY;
}

void GLFWInput::setGLFWWindow(Window *window) {
    GLFW_Window* glfwWindow = dynamic_cast<GLFW_Window*>(window);

    if (!glfwWindow) {
        Logger::error("Window is not a GLFW_Window, GLFWInput only works with a GLFW_Window.");

        return;
    }

    GLFWwindow* inputWindow = glfwWindow->getWindow();

    if (!inputWindow) {
        Logger::error("Window system does not seem to be initialized, initialize GLFW_Window first.");

        return;
    }

    m_window = inputWindow;
}
