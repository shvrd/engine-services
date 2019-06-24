//
// Created by thekatze on 06/01/2019.
//

#ifndef ENGINITO_FILEUTILS_H
#define ENGINITO_FILEUTILS_H


#include <string>
#include <vector>

class FileUtils {
public:
    FileUtils() = delete;
    ~FileUtils() = delete;

    static std::string readTextFile(const std::string& filePath);
    static std::vector<char> readBinaryFile(const std::string& filePath);

};

#endif //ENGINITO_FILEUTILS_H
