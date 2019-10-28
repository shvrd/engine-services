//
// Created by thekatze on 21/07/2019.
//

#ifndef ENGINITO_IMAGELOADER_H
#define ENGINITO_IMAGELOADER_H

#include <memory>
#include <string>
#include "../../../../resources/Texture.h"

class ImageLoader {
public:
    static std::shared_ptr<Texture> loadFromPNG(const std::string& filePath);
    static std::shared_ptr<Texture> loadFromCharArray(const char* image, unsigned int width, unsigned int height);
};


#endif //ENGINITO_IMAGELOADER_H
