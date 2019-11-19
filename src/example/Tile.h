//
// Created by thekatze on 17/11/2019.
//

#ifndef SHVRD_TILE_H
#define SHVRD_TILE_H

class Entity;

struct Tile {
    unsigned int m_textureId;
    Entity* m_entity;
    bool m_hasCollision;
};

#endif //SHVRD_TILE_H
