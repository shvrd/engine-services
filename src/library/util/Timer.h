//
// Created by thekatze on 16/12/2018.
//

#ifndef GENERIC_LIBRARY_TIMER_H
#define GENERIC_LIBRARY_TIMER_H

#include <chrono>

using Duration_t = unsigned int;

class Timer {
    using Clock_t = std::chrono::high_resolution_clock;
    using TimePoint_t = Clock_t::time_point;

    Clock_t m_clock;
    TimePoint_t m_startTime;

public:
    Timer();
    ~Timer() = default;

    void start();
    Duration_t get();

    void wait(Duration_t ms);
};


#endif //GENERIC_LIBRARY_TIMER_H
