//
// Created by thekatze on 11/11/2019.
//

#ifndef ENGINITO_OPENALAUDIO_H
#define ENGINITO_OPENALAUDIO_H

#include "../Audio.h"

#include <AL/al.h>
#include <AL/alc.h>

class OpenALAudio : public Audio {
    ALCdevice* m_device;
    ALCcontext* m_context;
    ALuint m_buffer;
public:
    void initialize() override;
    std::shared_ptr<Sound> loadSound(const std::string& filePath) override;
};


#endif //ENGINITO_OPENALAUDIO_H
