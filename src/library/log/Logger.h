//
// Created by thekatze on 24/11/2018.
//

#ifndef ENGINITO_LOGGER_H
#define ENGINITO_LOGGER_H

#include <string>
#include <mutex>

class Logger {

    static std::mutex m_logLock;
public:
    static void info(const std::string& message);
    static void warn(const std::string& message);
    static void error(const std::string& message);

    static void critical(const std::string& message, int exitCode);
};


#endif //ENGINITO_LOGGER_H
