//
// Created by thekatze on 24/12/2018.
//

#include "WindowServiceLocator.h"
#include "../log/Logger.h"

std::shared_ptr<Window> WindowServiceLocator::m_window = std::make_shared<NullWindow>();

void WindowServiceLocator::set(std::shared_ptr<Window> window) {
    if (window == nullptr) {
        m_window = std::make_shared<NullWindow>();

        return;
    }

    m_window = window;
}

std::shared_ptr<Window> WindowServiceLocator::get() {
    return m_window;
}
