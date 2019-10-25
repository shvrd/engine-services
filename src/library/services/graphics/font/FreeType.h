//
// Created by thekatze on 23/10/2019.
//

#ifndef ENGINITO_FREETYPE_H
#define ENGINITO_FREETYPE_H

#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

class FreeType {
    FT_Library m_library;
    FT_Face m_currentFace;

public:
    void initialize();

    void useFont(std::string fontName);
    void setFontSize(unsigned int fontSize);
};


#endif //ENGINITO_FREETYPE_H
