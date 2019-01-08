//
// Created by thekatze on 22/12/2018.
//

#ifndef ENGINITO_TIMERUTILS_H
#define ENGINITO_TIMERUTILS_H

#include "Timer.h"

class TimerUtils {
public:
    TimerUtils() = delete;
    ~TimerUtils() = delete;

    static Duration_t calculateFrameTimeForFPS(unsigned int fps);
};


#endif //ENGINITO_TIMERUTILS_H
