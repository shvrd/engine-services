//
// Created by thekatze on 21/07/2019.
//

#include "ImageLoader.h"
#include "../../../../util/FileUtils.h"
#include "../../../../util/png/PicoPNG.h"
#include "../../../../log/Logger.h"

#include <vector>
#include <GL/glew.h>

std::shared_ptr<Texture> ImageLoader::loadFromPNG(const std::string &filePath) {
    std::vector<unsigned char> imageData;

    unsigned long width, height;

    std::vector<char> encodedData = FileUtils::readBinaryFile(filePath);

    if (int errorCode = decodePNG(imageData, width, height, reinterpret_cast<unsigned char*>(encodedData.data()), encodedData.size())) {
        Logger::warn("decodePNG failed with error code " + std::to_string(errorCode));
    }

    return loadFromCharArray(reinterpret_cast<char*>(imageData.data()), width, height);
}

std::shared_ptr<Texture>
ImageLoader::loadFromCharArray(const char *image, const unsigned int width, const unsigned int height) {
    std::shared_ptr<Texture> texture = std::make_shared<Texture>();

    texture->width = width;
    texture->height = height;

    glGenTextures(1, &texture->id);

    glBindTexture(GL_TEXTURE_2D, texture->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) width, (GLsizei) height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    //TODO: Make this stuff configurable

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    return texture;
}
