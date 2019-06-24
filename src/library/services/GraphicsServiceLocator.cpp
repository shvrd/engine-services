//
// Created by thekatze on 25/12/2018.
//

#include "GraphicsServiceLocator.h"
#include "graphics/NullGraphics.h"

std::shared_ptr<Graphics> GraphicsServiceLocator::m_graphics = std::make_shared<NullGraphics>();

std::shared_ptr<Graphics> GraphicsServiceLocator::get() {
    return m_graphics;
}

void GraphicsServiceLocator::set(std::shared_ptr<Graphics> graphics) {
    if (graphics == nullptr) {
        m_graphics = std::make_shared<NullGraphics>();

        return;
    }

    m_graphics = graphics;
}
