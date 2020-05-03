//
// Created by thekatze on 11/11/2019.
//

#ifndef SHVRD_OPENALAUDIO_H
#define SHVRD_OPENALAUDIO_H

#include "../Audio.h"

#include <AL/al.h>
#include <AL/alc.h>

class OpenALAudio : public Audio {
    ALCdevice* m_device;
    ALCcontext* m_context;
    ALuint m_source;
public:
    void initialize() override;
    std::shared_ptr<Sound> loadSound(const std::string& filePath) override;
    void playSound(std::shared_ptr<Sound> sound) override;
};


#endif //SHVRD_OPENALAUDIO_H
