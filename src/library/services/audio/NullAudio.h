//
// Created by thekatze on 11/11/2019.
//

#ifndef ENGINITO_NULLAUDIO_H
#define ENGINITO_NULLAUDIO_H

#include "Audio.h"

class NullAudio : public Audio {
public:
    void initialize() override {}
    std::shared_ptr<Sound> loadSound(const std::string& filePath) override { return std::make_shared<Sound>(); }
};

#endif //ENGINITO_NULLAUDIO_H
