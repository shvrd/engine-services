//
// Created by thekatze on 24/12/2018.
//

#include "GLFWInput.h"
#include "../../log/Logger.h"

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
    return false;
}

bool GLFWInput::isKeyReleased(Key key) {
    return true;
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

void GLFWInput::setGLFWWindow(GLFWwindow *window) {
    m_window = window;
}
