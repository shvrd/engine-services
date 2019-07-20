//
// Created by thekatze on 20/07/2019.
//

#include "ResourceManager.h"

ResourceManager::ResourceManager() : m_textureMap() {

}

ResourceManager::~ResourceManager() {
    m_textureMap.clear();
}

Texture ResourceManager::loadTexture(std::string filePath) {
    return Texture();
}
