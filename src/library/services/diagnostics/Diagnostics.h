//
// Created by thekatze on 24/06/2019.
//

#ifndef SHVRD_DIAGNOSTICS_H
#define SHVRD_DIAGNOSTICS_H

class Diagnostics {
public:
    virtual unsigned long getMemoryUsage() = 0;
    virtual unsigned long getAvailableMemory() = 0;
    virtual float getCPUUsage() = 0;
};

#endif //SHVRD_DIAGNOSTICS_H
