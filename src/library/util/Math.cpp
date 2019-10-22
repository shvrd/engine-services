//
// Created by thekatze on 22/10/2019.
//

#include "Math.h"

namespace Math {
    int getNextPowerOfTwo(int value) {

        int power = 0b1;
        while (power < value)
            power = power << 1;

        return power;
    }
}