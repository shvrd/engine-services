//
// Created by thekatze on 11/11/2019.
//

#include "OpenALAudio.h"
#include "../../../log/Logger.h"

void OpenALAudio::initialize() {
    // Open default device
    m_audioDevice = alcOpenDevice(nullptr);

    if (!m_audioDevice) {
        Logger::error("Default audio device could not be opened.");

        return;
    }
}
