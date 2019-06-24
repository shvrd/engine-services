//
// Created by thekatze on 06/01/2019.
//

#include "FileUtils.h"

#include <fstream>
#include <sstream>
#include "../log/Logger.h"

std::string FileUtils::readTextFile(const std::string &filePath) {
    std::ifstream fileInputStream(filePath, std::ios::in);

    if (!fileInputStream.is_open()) {
        Logger::error("Failed to open file: " + filePath);

        return "";
    }

    std::stringstream fileContents;
    fileContents << fileInputStream.rdbuf();

    return fileContents.str();
}

std::vector<char> FileUtils::readBinaryFile(const std::string &filePath) {
    std::ifstream fileInputStream(filePath, std::ios::binary);

    if (!fileInputStream.is_open()) {
        Logger::error("Failed to open file: " + filePath);

        return {};
    }


    return std::vector(std::istreambuf_iterator<char>(fileInputStream), {});
}
