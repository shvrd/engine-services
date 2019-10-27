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

    std::shared_ptr<Letter> loadLetter(unsigned long letter);
public:
    void initialize();

    void useFont(const std::string& fontName, unsigned int fontSize = 14);
    void setFontSize(unsigned int fontSize);

    void cacheCommonCharacters();

    std::shared_ptr<Letter> getLetter(unsigned long letter);
    inline std::shared_ptr<Letter> getLetter(char letter) { return getLetter(static_cast<unsigned long>(letter)); }
};

#endif //ENGINITO_FREETYPE_H
