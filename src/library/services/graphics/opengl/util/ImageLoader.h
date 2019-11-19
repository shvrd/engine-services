//
// Created by thekatze on 21/07/2019.
//

#ifndef SHVRD_IMAGELOADER_H
#define SHVRD_IMAGELOADER_H

#include <memory>
#include <string>
#include "../../../../resources/Texture.h"

class ImageLoader {
public:
    static std::shared_ptr<Texture> loadFromPNG(const std::string& filePath);
    static std::shared_ptr<Texture> loadFromRGBACharArray(const unsigned char* image, unsigned int width, unsigned int height);
    static std::shared_ptr<Texture> loadFromGrayscaleCharArray(const unsigned char* image, unsigned int width, unsigned int height);
};


#endif //SHVRD_IMAGELOADER_H
