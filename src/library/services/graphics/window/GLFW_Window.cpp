//
// Created by thekatze on 23/12/2018.
//

#include "GLFW_Window.h"
#include "../../../log/Logger.h"
#include "../../GraphicsServiceLocator.h"
#include "../../WindowServiceLocator.h"

void resizeCallback(GLFWwindow* window, int width, int height) {
    Logger::info("Resize: " + std::to_string(width) + " x " + std::to_string(height));

    // No access to GLFW_Window here - use the service locator
    WindowServiceLocator::get()->setDimensions(width, height);
    GraphicsServiceLocator::get()->setViewport(width, height);
}

void GLFW_Window::initialize(unsigned int width, unsigned int height, const std::string &windowTitle) {
    if (!glfwInit()) {
        Logger::critical("GLFW could not be initialized, terminating.", -2);
    }

    m_window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);

    if (!m_window) {
        glfwTerminate();
        Logger::critical("Window could not be created, terminating", -3);
    }

    // TODO: Make VSync configurable
    glfwSwapInterval(1);
    glfwMakeContextCurrent(m_window);

    glfwSetWindowSizeCallback(m_window, resizeCallback);

    glfwGetFramebufferSize(m_window, &m_windowWidth, &m_windowHeight);
    Logger::info("Framebuffer size: " + std::to_string(m_windowWidth) + " x " + std::to_string(m_windowHeight));
}

void GLFW_Window::swapBuffers() {
    glfwSwapBuffers(m_window);
}

void GLFW_Window::pollEvents() {
    glfwPollEvents();
}

bool GLFW_Window::windowShouldClose() {
    return glfwWindowShouldClose(m_window) != 0;
}

GLFW_Window::~GLFW_Window() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

GLFWwindow *GLFW_Window::getWindow() {
    return m_window;
}


