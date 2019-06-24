//
// Created by thekatze on 24/06/2019.
//

#ifndef ENGINITO_DIAGNOSTICS_H
#define ENGINITO_DIAGNOSTICS_H

class Diagnostics {
public:
    virtual unsigned long getMemoryUsage() = 0;
    virtual unsigned long getAvailableMemory() = 0;
    virtual float getCPUUsage() = 0;
};

#endif //ENGINITO_DIAGNOSTICS_H
