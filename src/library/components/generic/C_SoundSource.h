//
// Created by thekatze on 04/05/2020.
//

#ifndef SHVRD_C_SOUNDSOURCE_H
#define SHVRD_C_SOUNDSOURCE_H

#include <memory>
#include "../Component.h"
#include "../../services/audio/SoundSource.h"
#include "../../services/AudioServiceLocator.h"

class C_SoundSource : public Component {
    std::shared_ptr<SoundSource> m_source;

public:
    C_SoundSource();
    ~C_SoundSource() = default;

    std::shared_ptr<SoundSource> getSource();
};

C_SoundSource::C_SoundSource() {
    m_source = AudioServiceLocator::get()->createSoundSource();
}

std::shared_ptr<SoundSource> C_SoundSource::getSource() {
    return m_source;
}

#endif //SHVRD_C_SOUNDSOURCE_H
