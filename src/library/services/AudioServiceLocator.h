//
// Created by thekatze on 11/11/2019.
//

#ifndef ENGINITO_AUDIOSERVICELOCATOR_H
#define ENGINITO_AUDIOSERVICELOCATOR_H

#include <memory>
#include "audio/Audio.h"

class AudioServiceLocator {
    static std::shared_ptr<Audio> m_audio;
public:
    static std::shared_ptr<Audio> get();

    static void set(std::shared_ptr<Audio> m_audio);
};


#endif //ENGINITO_AUDIOSERVICELOCATOR_H
