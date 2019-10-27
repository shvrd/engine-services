//
// Created by thekatze on 24/11/2018.
//

#include <iostream>
#include <thread>
#include "Logger.h"

std::mutex Logger::m_logLock;
Timer Logger::m_timer;

/**
 * Thread safe info message
 * @param message The message to log
 */
void Logger::info(const std::string &message) {
#ifdef BUILD_DEBUG
    std::lock_guard<std::mutex> lock(m_logLock);
    std::cout << "[Thread " << std::this_thread::get_id() << " @ " << m_timer.get() / 1000 << "ms - info] " << message << std::endl;
#endif
}

/**
 * Thread safe warning message
 * @param message The message to log
 */
void Logger::warn(const std::string &message) {
#ifdef BUILD_DEBUG
    std::lock_guard<std::mutex> lock(m_logLock);
    std::cout << "[Thread " << std::this_thread::get_id() << " @ " << m_timer.get() / 1000 << "ms - warning] " << message << std::endl;
#endif
}

/**
 * NON THREAD SAFE error message, prints to log relentlessly.
 * @param message The message to log
 */
void Logger::error(const std::string &message) {
    std::cout << "[Thread " << std::this_thread::get_id() << " @ " << m_timer.get() / 1000 << "ms - error] " << message << std::endl;
}

/**
 * Terminates the program, providing an error message and exit code.
 * @param message The message to log
 * @param exitCode The exit code to return on exit
 */
void Logger::critical(const std::string &message, int exitCode = -1) {
    std::cout << "[Thread " << std::this_thread::get_id() << " @ " << m_timer.get() / 1000 << "ms - critical] " << message << std::endl;
    std::exit(exitCode);
}
