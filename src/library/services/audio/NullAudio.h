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
    void playSound(std::shared_ptr<Sound> sound) override {}
};

#endif //SHVRD_NULLAUDIO_H
