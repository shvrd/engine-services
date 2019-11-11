//
// Created by thekatze on 11/11/2019.
//

#include "OpenALAudio.h"
#include "../../../log/Logger.h"

void OpenALAudio::initialize() {
    // Open default device
    m_device = alcOpenDevice(nullptr);

    if (!m_device) {
        Logger::error("Default audio device could not be opened, error code " + std::to_string(alGetError()));

        return;
    }

    // Create and bind context
    m_context = alcCreateContext(m_device, nullptr);

    if (!alcMakeContextCurrent(m_context)) {
        Logger::error("Failed to bind audio context, error code " + std::to_string(alGetError()));

        return;
    }

    alGenBuffers(1, &m_buffer);
    if (alGetError() == AL_INVALID_VALUE) {
        Logger::info("Buffer could not be generated, array not large enough");
    }
}

std::shared_ptr<Sound> OpenALAudio::loadSound(const std::string &filePath) {
    if (auto sound = m_sounds.get(filePath)) {
        return sound;
    }

    std::shared_ptr<Sound> sound = std::make_shared<Sound>();

    alGenSources(1, &sound->id);

    alSourcei(sound->id, AL_BUFFER, m_buffer);

    return sound;
}
