//
// Created by thekatze on 23/12/2018.
//

#ifndef SHVRD_WINDOW_H
#define SHVRD_WINDOW_H

#include <string>

#include "../../../types/Vector.h"

class Window {
protected:
    unsigned int m_windowWidth, m_windowHeight;

    bool m_resized;
public:
    Window()
    : m_windowWidth(0)
    , m_windowHeight(0)
    , m_resized(false) {}

    virtual ~Window() = default;

    virtual void initialize(unsigned int width, unsigned int height, const std::string& windowTitle) = 0;

    virtual void swapBuffers() = 0;
    virtual void pollEvents() = 0;

    virtual void setTitle(const std::string& title) = 0;

    virtual bool windowShouldClose() = 0;

    void setDimensions(unsigned int width, unsigned int height) {
        m_windowWidth = width;
        m_windowHeight = height;

        m_resized = true;
    }

    Vector2f getDimensions() const {
        return Vector2f{static_cast<float>(m_windowWidth), static_cast<float>(m_windowHeight)};
    }

    bool hasResized() {
        return m_resized;
    }

    void resetResizeFlag() {
        m_resized = false;
    }
};


#endif //SHVRD_WINDOW_H
