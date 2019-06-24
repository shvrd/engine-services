//
// Created by thekatze on 24/06/2019.
//

#ifndef ENGINITO_WINDOWSDIAGNOSTICS_H
#define ENGINITO_WINDOWSDIAGNOSTICS_H

#include "Diagnostics.h"

class WindowsDiagnostics : public Diagnostics {
public:
    unsigned long getMemoryUsage() override;
    unsigned long getAvailableMemory() override;
    float getCPUUsage() override;
};


#endif //ENGINITO_WINDOWSDIAGNOSTICS_H
