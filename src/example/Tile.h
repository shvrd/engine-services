//
// Created by thekatze on 17/11/2019.
//

#ifndef ENGINITO_TILE_H
#define ENGINITO_TILE_H

class Entity;

struct Tile {
    unsigned int m_textureId;
    Entity* m_entity;
    bool m_hasCollision;
};

#endif //ENGINITO_TILE_H
