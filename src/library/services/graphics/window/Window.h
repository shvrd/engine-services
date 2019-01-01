//
// Created by thekatze on 23/12/2018.
//

#ifndef GENERIC_LIBRARY_WINDOW_H
#define GENERIC_LIBRARY_WINDOW_H

#include <string>

class Window {
protected:
    int m_windowWidth, m_windowHeight;
public:
    Window() = default;
    virtual ~Window() = default;

    virtual void initialize(unsigned int width, unsigned int height, const std::string& windowTitle) = 0;

    virtual void swapBuffers() = 0;
    virtual void pollEvents() = 0;

    virtual bool windowShouldClose() = 0;
};


#endif //GENERIC_LIBRARY_WINDOW_H
