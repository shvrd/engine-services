//
// Created by thekatze on 24/12/2018.
//

#include "GLFWInput.h"
#include "../../log/Logger.h"
#include "../graphics/window/GLFW_Window.h"
#include "../../types/Vector.h"
#include "../InputServiceLocator.h"

void GLFWInput::update() {
    int mouseXOld = m_mouseX;
    int mouseYOld = m_mouseY;

    double x, y;
    glfwGetCursorPos(m_window, &x, &y);

    m_mouseX = static_cast<int>(x);
    m_mouseY = static_cast<int>(y);

    m_deltaMouseX = m_mouseX - mouseXOld;
    m_deltaMouseY = m_mouseY - mouseYOld;

    m_hasPolled = false;
    m_frameScroll = {};
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

    // Set scroll callback
    glfwSetScrollCallback(m_window, scrollCallback);
}

bool GLFWInput::isMousePressed(MouseButton mouseButton) {
    return glfwGetMouseButton(m_window, static_cast<int>(mouseButton)) == GLFW_PRESS;
}

const Vector2f GLFWInput::getMouseScroll() {
    if (!m_hasPolled && m_hasScrolled) {
        m_frameScroll = m_scroll;
        m_hasPolled = true;
        m_hasScrolled = false;
    }

    return m_frameScroll;
}

void GLFWInput::scrollCallback(GLFWwindow *window, double x, double y) {
    // I hate every single character of this line
    InputServiceLocator::get()->setMouseScroll({static_cast<float>(x), static_cast<float>(y)});
}

void GLFWInput::setMouseScroll(Vector2f mouseScroll) {
    m_scroll = mouseScroll;
    m_hasScrolled = true;
}
