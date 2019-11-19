//
// Created by thekatze on 20/07/2019.
//

#ifndef SHVRD_PICOPNG_H
#define SHVRD_PICOPNG_H

#include <vector>

extern int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height, const unsigned char* in_png, size_t in_size, bool convert_to_rgba32 = true);

#endif //SHVRD_PICOPNG_H
