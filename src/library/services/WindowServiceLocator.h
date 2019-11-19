//
// Created by thekatze on 24/12/2018.
//

#ifndef SHVRD_WINDOWSERVICELOCATOR_H
#define SHVRD_WINDOWSERVICELOCATOR_H

#include <memory>
#include "graphics/window/NullWindow.h"
#include "graphics/window/Window.h"

class WindowServiceLocator {
    static std::shared_ptr<Window> m_window;
public:

    static std::shared_ptr<Window> get();

    static void set(std::shared_ptr<Window> window);
};

#endif //SHVRD_WINDOWSERVICELOCATOR_H
