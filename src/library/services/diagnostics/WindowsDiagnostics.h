//
// Created by thekatze on 24/06/2019.
//

#ifndef SHVRD_WINDOWSDIAGNOSTICS_H
#define SHVRD_WINDOWSDIAGNOSTICS_H

#include "Diagnostics.h"

class WindowsDiagnostics : public Diagnostics {
public:
    unsigned long getMemoryUsage() override;
    unsigned long getAvailableMemory() override;
    float getCPUUsage() override;
};


#endif //SHVRD_WINDOWSDIAGNOSTICS_H
