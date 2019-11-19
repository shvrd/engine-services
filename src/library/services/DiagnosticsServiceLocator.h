//
// Created by thekatze on 25/12/2018.
//

#ifndef SHVRD_DIAGNOSTICSSERVICELOCATOR_H
#define SHVRD_DIAGNOSTICSSERVICELOCATOR_H

#include <memory>
#include "diagnostics/Diagnostics.h"

class DiagnosticsServiceLocator {
    static std::shared_ptr<Diagnostics> m_diagnostics;
public:
    static std::shared_ptr<Diagnostics> get();

    static void set(std::shared_ptr<Diagnostics> m_diagnostics);
};


#endif //SHVRD_DIAGNOSTICSSERVICELOCATOR_H
