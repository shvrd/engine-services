//
// Created by thekatze on 23/10/2019.
//

#include "FreeType.h"

#include FT_BITMAP_H

#include <limits>
#include <sstream>

#include "../../../log/Logger.h"

FreeType::FreeType() {
    Logger::info("Initializing FreeType");

    if (FT_Init_FreeType(&m_library)) {
        Logger::error("Could not initialize FreeType");

        return;
    }

    FT_Int major, minor, patch;

    FT_Library_Version(m_library, &major, &minor, &patch);

    std::stringstream versionString;
    versionString << "Using FreeType version " << major << "." << minor << "." << patch;

    Logger::info(versionString.str());
}

FreeType::~FreeType() {
    FT_Done_FreeType(m_library);
}

void FreeType::useFont(const std::string& fontName, const unsigned int fontSize) {
    Logger::info("Loading font " + fontName);

    if (FT_New_Face(m_library, fontName.c_str(), 0, &m_currentFace)) {
        Logger::error("Could not open font " + fontName);

        return;
    }

    setFontSize(fontSize);

    // TODO: This has some weird side effect, some textures wont load correctly if letters are cached
    // preloadCommonCharacters();
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

void FreeType::preloadCommonCharacters() {
    // TODO: This has some weird side effect, some textures wont load correctly if letters are cached
    unsigned long MIN = 0;
    unsigned long MAX = 64;

    for (unsigned long character = MIN; character < MAX; ++character) {
        loadLetter(character);
    }
}

std::shared_ptr<Letter> FreeType::loadLetter(unsigned long character) {
    if (FT_Load_Char(m_currentFace, character, FT_LOAD_RENDER)) {
        Logger::error("Could not load character " + std::string(1, character));

        return std::shared_ptr<Letter>();
    }

    FT_GlyphSlot& glyph = m_currentFace->glyph;

    Letter letter = {
            .id = character,
            .textureId = 0,
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

    cache(sharedLetter);

    return sharedLetter;
}

void FreeType::setTextShader(const std::shared_ptr<Shader> shader) {
    m_textShader = shader;
}

std::shared_ptr<Shader> FreeType::getTextShader() {
    return m_textShader;
}

void FreeType::cache(std::shared_ptr<Letter> letter) {
    m_letters.add(std::to_string(letter->id), letter);
}

