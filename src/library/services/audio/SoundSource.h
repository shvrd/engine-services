//
// Created by thekatze on 04/05/2020.
//

#ifndef SHVRD_SOUNDSOURCE_H
#define SHVRD_SOUNDSOURCE_H

#include "../../types/Vector.h"

struct SoundSource {
    unsigned int id = 0;

    float getGain() const {
        return m_gain;
    }

    float getPitch() const {
        return m_pitch;
    }

    Vector3f getLocation() const {
        return m_location;
    }

    bool isLooping() const {
        return m_looping;
    }

    bool isDirty() const {
        return m_dirty;
    }

    void resetDirtyFlag() {
        m_dirty = false;
    }

    void setGain(float gain) {
        m_gain = gain;

        m_dirty = true;
    }

    void setPitch(float pitch) {
        m_pitch = pitch;

        m_dirty = true;
    }

    void setLocation(Vector3f& location) {
        m_location = location;

        m_dirty = true;
    }

    void setLooping(bool looping) {
        m_looping = looping;

        m_dirty = true;
    }

private:
    bool m_dirty = true;
    float m_gain = 1.f;
    float m_pitch = 1.f;

    Vector3f m_location = {};

    bool m_looping = false;
};

#endif //SHVRD_SOUNDSOURCE_H
