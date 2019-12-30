//
// Created by thekatze on 30/12/2019.
//

#ifndef SHVRD_C_COLLIDABLE_H
#define SHVRD_C_COLLIDABLE_H

#include <cstdlib>

#include <components/Component.h>
#include <components/Entity.h>
#include <types/Rect.h>
#include "C_TileMap.h"
#include "C_Transform.h"

class C_Collidable : public Component {
    Rectf m_box;
    C_TileMap* m_tileMap;

    void resolveTileCollision(Rectf& transformedBox, Rectf tileCollider);

public:
    C_Collidable(Rectf box, C_TileMap* tileMap)
        : m_box(box)
        , m_tileMap(tileMap) {}

    virtual void update();
};

void C_Collidable::update() {
    Rectf box = m_box;

    C_Transform* transform = getParent()->getComponent<C_Transform>();

    if (transform) {
        box = box + Rectf{transform->m_location, {0.f, 0.f}};
    }

    unsigned int tileWidth = m_tileMap->getTileWidth();
    unsigned int tileHeight = m_tileMap->getTileHeight();

    int tileMinX = (int)box.min().x / tileWidth;
    int tileMinY = (int)box.min().y / tileHeight;

    int tileMaxX = (int)box.max().x / tileWidth;
    int tileMaxY = (int)box.max().y / tileHeight;

    for (int x = tileMinX; x <= tileMaxX; ++x) {
        for (int y = tileMinY; y <= tileMaxY; ++y) {
            const Tile& tile = m_tileMap->getTileAt(x, y);

            if (tile.m_hasCollision) {
                resolveTileCollision(box, Rectf{Vector2f{(float)x * tileWidth, (float)y * tileHeight}, Vector2f{(float) tileWidth, (float) tileHeight}});
            }
        }
    }

}

void C_Collidable::resolveTileCollision(Rectf& transformedBox, Rectf tileCollider) {
    C_Transform* transform = getParent()->getComponent<C_Transform>();

    Vector2f intersectionVector = tileCollider.getIntersectionVector(transformedBox);

    if (transform) {
        if (std::abs(intersectionVector.x) < std::abs(intersectionVector.y)) {
            transform->m_location.x += intersectionVector.x;
            transformedBox.m_location.x += intersectionVector.x;
        } else {
            transform->m_location.y += intersectionVector.y;
            transformedBox.m_location.y += intersectionVector.y;
        }
    }

}

#endif //SHVRD_C_COLLIDABLE_H
