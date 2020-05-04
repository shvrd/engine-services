//
// Created by thekatze on 11/11/2019.
//

#ifndef SHVRD_NULLAUDIO_H
#define SHVRD_NULLAUDIO_H

#include "Audio.h"

class NullAudio : public Audio {
public:
    void initialize() override {}
    std::shared_ptr<Sound> loadSound(const std::string& filePath) override { return std::make_shared<Sound>(); }

    std::shared_ptr<SoundSource> createSoundSource() override { return std::make_shared<SoundSource>(); };

    void playSound(std::shared_ptr<Sound> sound, std::shared_ptr<SoundSource> source) override {}
};

#endif //SHVRD_NULLAUDIO_H
