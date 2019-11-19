//
// Created by thekatze on 06/01/2019.
//

#ifndef SHVRD_FILEUTILS_H
#define SHVRD_FILEUTILS_H


#include <string>
#include <vector>

class FileUtils {
public:
    FileUtils() = delete;
    ~FileUtils() = delete;

    static std::string readTextFile(const std::string& filePath);
    static std::vector<char> readBinaryFile(const std::string& filePath);

};

#endif //SHVRD_FILEUTILS_H
