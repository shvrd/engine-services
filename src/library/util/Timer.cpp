//
// Created by thekatze on 16/12/2018.
//

#include "Timer.h"

#include <thread>

Timer::Timer()
    : m_clock()
    , m_startTime(m_clock.now()) {
}

void Timer::start() {
    m_startTime = m_clock.now();
}

Duration_t Timer::get() {
    using namespace std::chrono;
    return duration_cast<duration<Duration_t, std::micro>>(m_clock.now() - m_startTime).count();
}

void Timer::wait(Duration_t microseconds) {
    std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
}
