//
// Created by thekatze on 11/11/2019.
//

#ifndef ENGINITO_NULLAUDIO_H
#define ENGINITO_NULLAUDIO_H

#include "Audio.h"

class NullAudio : public Audio {
public:
    void initialize() override {}
};

#endif //ENGINITO_NULLAUDIO_H
