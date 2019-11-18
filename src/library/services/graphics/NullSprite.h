//
// Created by thekatze on 17/02/19.
//

#ifndef ENGINITO_NULLSPRITE_H
#define ENGINITO_NULLSPRITE_H

#include "Sprite.h"

class NullSprite : public Sprite {
    void updateBuffer() override {};
public:
    NullSprite(const Vector2f& location, const Vector2f& dimensions) : Sprite(location, dimensions) {}
    ~NullSprite() override = default;

    void setTexture(const std::shared_ptr<Texture> texture) override {
        Sprite::setTexture(texture);
    }
};

#endif //ENGINITO_NULLSPRITE_H
