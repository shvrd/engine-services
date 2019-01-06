//
// Created by thekatze on 06/01/2019.
//

#ifndef ENGINITO_FILEUTILS_H
#define ENGINITO_FILEUTILS_H


#include <string>

class FileUtils {
public:
    FileUtils() = delete;
    ~FileUtils() = delete;

    static std::string readFile(const std::string& filePath);

};

#endif //ENGINITO_FILEUTILS_H
