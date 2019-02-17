//
// Created by thekatze on 17/02/19.
//

#ifndef ENGINITO_NULLSPRITE_H
#define ENGINITO_NULLSPRITE_H

#include "Sprite.h"

class NullSprite : public Sprite {
public:
    NullSprite(Vector2 location, Vector2 dimensions) : Sprite(location, dimensions) {}
    ~NullSprite() override = default;

    void setTexture(Texture texture) override {}
    void draw() override {}
};

#endif //ENGINITO_NULLSPRITE_H
