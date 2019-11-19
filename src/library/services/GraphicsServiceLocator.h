//
// Created by thekatze on 25/12/2018.
//

#ifndef SHVRD_GRAPHICSSERVICELOCATOR_H
#define SHVRD_GRAPHICSSERVICELOCATOR_H

#include <memory>
#include "graphics/Graphics.h"

class GraphicsServiceLocator {
    static std::shared_ptr<Graphics> m_graphics;
public:
    static std::shared_ptr<Graphics> get();

    static void set(std::shared_ptr<Graphics> m_graphics);
};


#endif //SHVRD_GRAPHICSSERVICELOCATOR_H
