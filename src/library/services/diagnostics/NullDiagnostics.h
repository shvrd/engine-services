//
// Created by thekatze on 24/06/2019.
//

#ifndef ENGINITO_NULLDIAGNOSTICS_H
#define ENGINITO_NULLDIAGNOSTICS_H

#include "Diagnostics.h"

class NullDiagnostics : public Diagnostics {
public:
    unsigned long getMemoryUsage() override { return 0L; }
    unsigned long getAvailableMemory() override { return 0L; }
    float getCPUUsage() override { return 0.0f; }
};

#endif //ENGINITO_NULLDIAGNOSTICS_H
