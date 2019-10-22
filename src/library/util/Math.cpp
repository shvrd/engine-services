//
// Created by thekatze on 22/10/2019.
//

#include "Math.h"

unsigned int Math::getNextPowerOfTwo(unsigned int value) {
    unsigned int power = 1;

    while (power < value)
        power <<= 1;

    return power;
}
