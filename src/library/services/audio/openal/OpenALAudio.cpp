//
// Created by thekatze on 11/11/2019.
//

#include "OpenALAudio.h"
#include "../../../log/Logger.h"
#include "../../../util/audio/stb_vorbis.h"

void OpenALAudio::initialize() {
    // Open default device
    m_device = alcOpenDevice(nullptr);

    if (!m_device) {
        Logger::error("Default audio device could not be opened, error code " + std::to_string(alGetError()));

        return;
    }

    // Create and bind context
    m_context = alcCreateContext(m_device, nullptr);

    if (!alcMakeContextCurrent(m_context)) {
        Logger::error("Failed to bind audio context, error code " + std::to_string(alGetError()));

        return;
    }


}

std::shared_ptr<Sound> OpenALAudio::loadSound(const std::string &filePath) {
    if (auto sound = m_sounds.get(filePath)) {
        return sound;
    }

    std::shared_ptr<Sound> sound = std::make_shared<Sound>();

    alGenBuffers(1, &sound->id);
    if (alGetError() == AL_INVALID_VALUE) {
        Logger::info("Buffer could not be generated, array not large enough");
    }

    Logger::info("Creating sound " + std::to_string(sound->id));

    short* data;
    int channels;
    int samples;
    int sampleRate;

    samples = stb_vorbis_decode_filename(filePath.c_str(), &channels, &sampleRate, &data);

    alBufferData(sound->id, AL_FORMAT_STEREO16, data, samples * 2 * sizeof(short), sampleRate);

    ALenum error = alGetError();

    if (error == AL_INVALID_VALUE) {
        Logger::info("Sound didn't load for some godforsaken reason.");
    }

    return sound;
}

void OpenALAudio::playSound(std::shared_ptr<Sound> sound, std::shared_ptr<SoundSource> source) {
    if (source->isDirty()) {
        updateSource(source);
    }

    alSourcei(source->id, AL_BUFFER, sound->id);
    alSourcePlay(source->id);
}

std::shared_ptr<SoundSource> OpenALAudio::createSoundSource() {
    std::shared_ptr<SoundSource> source = std::make_shared<SoundSource>();

    alGenSources(1, &source->id);

    updateSource(source);

    return source;
}

void OpenALAudio::updateSource(std::shared_ptr<SoundSource> source) {
    alSourcef(source->id, AL_PITCH, source->getPitch());
    alSourcef(source->id, AL_GAIN, source->getGain());

    Vector3f location = source->getLocation();
    alSource3f(source->id, AL_POSITION, location.x, location.y, location.z);

    alSource3f(source->id, AL_VELOCITY, 0, 0, 0);
    alSourcei(source->id, AL_LOOPING, source->isLooping());

    source->resetDirtyFlag();
}
