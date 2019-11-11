//
// Created by thekatze on 11/11/2019.
//

#include "AudioServiceLocator.h"
#include "audio/NullAudio.h"

std::shared_ptr<Audio> AudioServiceLocator::m_audio = std::make_shared<NullAudio>();

std::shared_ptr<Audio> AudioServiceLocator::get() {
    return m_audio;
}

void AudioServiceLocator::set(std::shared_ptr<Audio> audio) {
    if (audio == nullptr) {
        m_audio = std::make_shared<NullAudio>();

        return;
    }

    m_audio = audio;
}
