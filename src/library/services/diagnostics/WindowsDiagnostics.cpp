//
// Created by thekatze on 24/06/2019.
//

#include "WindowsDiagnostics.h"

#ifdef BUILD_WINDOWS

#include <windows.h>
#include <psapi.h>
#include <processthreadsapi.h>
#include <sysinfoapi.h>

unsigned long WindowsDiagnostics::getMemoryUsage() {
    PPROCESS_MEMORY_COUNTERS pmc;
    bool success = GetProcessMemoryInfo(GetCurrentProcess(), pmc, pmc->cb);
    return pmc->QuotaPagedPoolUsage;
}

unsigned long WindowsDiagnostics::getAvailableMemory() {
    LPMEMORYSTATUSEX memoryStatuSex;
    bool success = GlobalMemoryStatusEx(memoryStatuSex);
    return memoryStatuSex->ullAvailVirtual;
}

float WindowsDiagnostics::getCPUUsage() {
    // https://stackoverflow.com/questions/23143693/retrieving-cpu-load-percent-total-in-windows-with-c
    return 0;
}

#endif
