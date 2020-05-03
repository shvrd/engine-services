//
// Created by thekatze on 11/11/2019.
//

#ifndef SHVRD_AUDIO_H
#define SHVRD_AUDIO_H

#include <memory>

#include "../../resources/ResourceManager.h"
#include "../../resources/Sound.h"

class Audio {
protected:
    ResourceManager<Sound> m_sounds;
public:
    virtual void initialize() = 0;

    virtual std::shared_ptr<Sound> loadSound(const std::string& filePath) = 0;
    virtual void playSound(std::shared_ptr<Sound> sound) = 0;


};

#endif //SHVRD_AUDIO_H
