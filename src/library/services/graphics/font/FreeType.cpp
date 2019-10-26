//
// Created by thekatze on 23/10/2019.
//

#include "FreeType.h"
#include "../../../log/Logger.h"

void FreeType::initialize() {
    Logger::info("Initializing FreeType");

    if (FT_Init_FreeType(&m_library)) {
        Logger::error("Could not initialize FreeType");

        return;
    }
}

void FreeType::useFont(std::string fontName) {
    Logger::info("Loading font " + fontName);

    if (FT_New_Face(m_library, fontName.c_str(), 0, &m_currentFace)) {
        Logger::error("Could not open font " + fontName);

        return;
    }
}

void FreeType::setFontSize(unsigned int fontSize) {
    FT_Set_Pixel_Sizes(m_currentFace, 0, fontSize);
}

std::shared_ptr<Letter> FreeType::getLetter(char letter) {
    if (FT_Load_Char(m_currentFace, letter, FT_LOAD_RENDER)) {
        Logger::error("Could not load character " + std::to_string(letter));

        return std::shared_ptr<Letter>();
    }

    //TODO: Load from/to resourcemanager m_letters;
    return std::shared_ptr<Letter>();
}
