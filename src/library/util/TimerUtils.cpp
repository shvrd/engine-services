//
// Created by thekatze on 22/12/2018.
//

#include "TimerUtils.h"

Duration_t TimerUtils::calculateFrameTimeForFPS(unsigned int fps) {
    return 1000000/fps;
}
