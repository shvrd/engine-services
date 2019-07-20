//
// Created by thekatze on 20/07/2019.
//

#ifndef ENGINITO_RESOURCEMANAGER_H
#define ENGINITO_RESOURCEMANAGER_H

#include <map>
#include <string>
#include "../types/Texture.h"

class ResourceManager {
    std::map<std::string, Texture> m_textureMap;
public:
    ResourceManager();
    ~ResourceManager();

    Texture loadTexture(std::string filePath);
};


#endif //ENGINITO_RESOURCEMANAGER_H
