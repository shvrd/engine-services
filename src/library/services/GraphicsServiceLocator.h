//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_GRAPHICSSERVICELOCATOR_H
#define ENGINITO_GRAPHICSSERVICELOCATOR_H

#include <memory>
#include "graphics/Graphics.h"

class GraphicsServiceLocator {

public:
    static std::shared_ptr<Graphics> m_graphics;
public:
    static std::shared_ptr<Graphics> get();

    static void set(std::shared_ptr<Graphics> m_graphics);
};


#endif //ENGINITO_GRAPHICSSERVICELOCATOR_H
