//
// Created by thekatze on 25/12/2018.
//

#include "DiagnosticsServiceLocator.h"
#include "diagnostics/NullDiagnostics.h"

std::shared_ptr<Diagnostics> DiagnosticsServiceLocator::m_diagnostics = std::make_shared<NullDiagnostics>();

std::shared_ptr<Diagnostics> DiagnosticsServiceLocator::get() {
    return m_diagnostics;
}

void DiagnosticsServiceLocator::set(std::shared_ptr<Diagnostics> diagnostics) {
    if (diagnostics == nullptr) {
        m_diagnostics = std::make_shared<NullDiagnostics>();

        return;
    }

    m_diagnostics = diagnostics;
}
