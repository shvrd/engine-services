//
// Created by thekatze on 24/06/2019.
//

#ifndef SHVRD_NULLDIAGNOSTICS_H
#define SHVRD_NULLDIAGNOSTICS_H

#include "Diagnostics.h"

class NullDiagnostics : public Diagnostics {
public:
    unsigned long getMemoryUsage() override { return 0L; }
    unsigned long getAvailableMemory() override { return 0L; }
    float getCPUUsage() override { return 0.0f; }
};

#endif //SHVRD_NULLDIAGNOSTICS_H
