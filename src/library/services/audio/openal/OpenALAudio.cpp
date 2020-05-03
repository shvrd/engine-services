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

    alGenSources(1, &m_source);

    alSourcef(m_source, AL_PITCH, 1.f);
    alSourcef(m_source, AL_GAIN, 1.f);
    alSource3f(m_source, AL_POSITION, 0, 0, 0);
    alSource3f(m_source, AL_VELOCITY, 0, 0, 0);
    alSourcei(m_source, AL_LOOPING, AL_FALSE);
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

void OpenALAudio::playSound(std::shared_ptr<Sound> sound) {
    Logger::info("Playing sound " + std::to_string(sound->id));

    alSourcei(m_source, AL_BUFFER, sound->id);
    alSourcePlay(m_source);
}

//    AudioFile<float> audioFile;
//    audioFile.load(filePath);
//
//    audioFile.printSummary();
//
//    int format = 0x1100;
//
//    if (audioFile.getBitDepth() == 16) format += 0x0001;
//    if (audioFile.getNumChannels() == 2) format +=0x0002;
