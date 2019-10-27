//
// Created by thekatze on 23/10/2019.
//

#ifndef ENGINITO_FREETYPE_H
#define ENGINITO_FREETYPE_H

#include <memory>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../../../resources/ResourceManager.h"
#include "Letter.h"

class FreeType {
    FT_Library m_library;
    FT_Face m_currentFace;

    ResourceManager<Letter> m_letters;

public:
    void initialize();

    void useFont(const std::string& fontName);
    void setFontSize(unsigned int fontSize);

    std::shared_ptr<Letter> getLetter(char letter);
};

#endif //ENGINITO_FREETYPE_H
