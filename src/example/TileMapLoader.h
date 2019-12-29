//
// Created by thekatze on 28/12/2019.
//

#ifndef SHVRD_TILEMAPLOADER_H
#define SHVRD_TILEMAPLOADER_H

#include <vector>
#include <string>
#include "C_TileMap.h"

class TileMapLoader {
    static std::vector<std::string> split(const std::string& string, char delimiter);
public:
    static std::unique_ptr<C_TileMap> loadTileMap(const std::string& filePath);
};


#endif //SHVRD_TILEMAPLOADER_H
