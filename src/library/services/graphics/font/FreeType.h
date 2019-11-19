//
// Created by thekatze on 23/10/2019.
//

#ifndef SHVRD_FREETYPE_H
#define SHVRD_FREETYPE_H

#include <memory>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../../../resources/ResourceManager.h"
#include "../Shader.h"
#include "Letter.h"

class FreeType {
    FT_Library m_library;
    FT_Face m_currentFace;

    ResourceManager<Letter> m_letters;

    std::shared_ptr<Shader> m_textShader;

    std::shared_ptr<Letter> loadLetter(unsigned long letter);

public:
    void initialize();

    void useFont(const std::string& fontName, unsigned int fontSize = 42);
    void setFontSize(unsigned int fontSize);

    void preloadCommonCharacters();

    std::shared_ptr<Letter> getLetter(unsigned long letter);
    inline std::shared_ptr<Letter> getLetter(char letter) { return getLetter(static_cast<unsigned long>(letter)); }

    void setTextShader(std::shared_ptr<Shader> shader);
    std::shared_ptr<Shader> getTextShader();

    void cache(std::shared_ptr<Letter> letter);
};

#endif //SHVRD_FREETYPE_H
