//
// Created by thekatze on 28/12/2019.
//

#include <sstream>

#include <log/Logger.h>
#include <util/FileUtils.h>
#include "TileMapLoader.h"

std::unique_ptr<C_TileMap> TileMapLoader::loadTileMap(const std::string &filePath) {
    Logger::info("Loading TileMap");

    std::string textFile = FileUtils::readTextFile(filePath);

    // Make every line an item in an array
    std::vector<std::string> lines = split(textFile, '\n');

    // Line 0 defines size
    std::string x = split(lines[0], ' ')[0];
    std::string y = split(lines[0], ' ')[1];

    Logger::info("X: " + x + " Y: " + y);

    std::unique_ptr<C_TileMap> tileMap = std::make_unique<C_TileMap>(std::stoi(x), std::stoi(y));

    for (unsigned int y = 0; y < tileMap->getHeight(); ++y) {
        std::vector<std::string> tiles = split(lines[y + 1], ' ');
        for (unsigned int x = 0; x < tileMap->getWidth(); ++x) {
            tileMap->setTileAt(x, tileMap->getHeight() - y - 1, std::stoi(tiles[x]));
        }
    }

    return tileMap;
}

std::vector<std::string> TileMapLoader::split(const std::string &string, char delimiter) {
    std::stringstream ss(string);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimiter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}
