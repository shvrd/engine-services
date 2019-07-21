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
    static std::shared_ptr<Texture> loadPNG(const std::string& filePath);
};


#endif //ENGINITO_IMAGELOADER_H
