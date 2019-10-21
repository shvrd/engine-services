//
// Created by thekatze on 21/10/2019.
//

#ifndef ENGINITO_FREETYPE_H
#define ENGINITO_FREETYPE_H

#include <ft2build.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>

#include <GL/glew.h>

#include <string>
#include <vector>
#include "../../../../types/Vector.h"

struct FontData {
    float height;
    GLuint* textureIDs;
    GLuint firstDisplayList;

    void init(const std::string& fontFile, unsigned int height) {

    }

    //TODO: http://nehe.gamedev.net/tutorial/freetype_fonts_in_opengl/24001/
    void cleanUp() {}
};

class FreeType {
    static void print(const FontData& font, Vector2 location, std::string text);
};


#endif //ENGINITO_FREETYPE_H
