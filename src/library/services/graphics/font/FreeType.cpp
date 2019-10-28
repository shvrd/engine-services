//
// Created by thekatze on 23/10/2019.
//

#include "FreeType.h"

#include <limits>

#include "../../../log/Logger.h"

void FreeType::initialize() {
    Logger::info("Initializing FreeType");

    if (FT_Init_FreeType(&m_library)) {
        Logger::error("Could not initialize FreeType");

        return;
    }
}

void FreeType::useFont(const std::string& fontName, const unsigned int fontSize) {
    Logger::info("Loading font " + fontName);

    if (FT_New_Face(m_library, fontName.c_str(), 0, &m_currentFace)) {
        Logger::error("Could not open font " + fontName);

        return;
    }

    setFontSize(fontSize);
    cacheCommonCharacters();
}

void FreeType::setFontSize(unsigned int fontSize) {
    FT_Set_Pixel_Sizes(m_currentFace, 0, fontSize);
}

std::shared_ptr<Letter> FreeType::getLetter(unsigned long character) {
    // Try loading from cache
    if (std::shared_ptr<Letter> letter = m_letters.get(std::to_string(character))) {
        return letter;
    }

    return loadLetter(character);
}

void FreeType::cacheCommonCharacters() {
    const char MIN = std::numeric_limits<char>::min();
    const char MAX = std::numeric_limits<char>::max();

    for (char character = MIN; character < MAX; ++character) {
        loadLetter(static_cast<unsigned long>(character));
    }
}

std::shared_ptr<Letter> FreeType::loadLetter(unsigned long character) {
    if (FT_Load_Char(m_currentFace, character, FT_LOAD_RENDER)) {
        Logger::error("Could not load character " + std::string(1, character));

        return std::shared_ptr<Letter>();
    }

    auto& glyph = m_currentFace->glyph;

    Letter letter = {
            .id = 0,
            .bitmap = {
                    .buffer = glyph->bitmap.buffer,
                    .width = glyph->bitmap.width,
                    .height = glyph->bitmap.rows
            },
            .offset = {
                    .x = glyph->bitmap_left,
                    .y = glyph->bitmap_top
            },
            .advance = {
                    .x = glyph->advance.x,
                    .y = glyph->advance.y
            }
    };

    std::shared_ptr<Letter> sharedLetter = std::make_shared<Letter>(letter);

    m_letters.add(std::to_string(character), sharedLetter);

    return sharedLetter;
}
