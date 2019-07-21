//
// Created by thekatze on 21/07/2019.
//

#include "ImageLoader.h"
#include "../../../../util/FileUtils.h"
#include "../../../../util/png/PicoPNG.h"

#include <vector>

std::shared_ptr<Texture> ImageLoader::loadPNG(const std::string &filePath) {
    std::shared_ptr<Texture> texture = std::make_shared<Texture>();

    std::vector<unsigned char> imageData;

    unsigned long width, height;

    std::vector<char> encodedData = FileUtils::readBinaryFile(filePath);

    decodePNG(imageData, width, height, reinterpret_cast<unsigned char*>(encodedData.data()), encodedData.size());

    return std::shared_ptr<Texture>();
}
