//
// Created by thekatze on 11/12/2018.
//

#ifndef SHVRD_SCENE_H
#define SHVRD_SCENE_H

#include <memory>

#include "../services/input/Input.h"
#include "../services/graphics/Graphics.h"
#include "SceneStack.h"

class Scene {
protected:
    friend class SceneStack;
    std::shared_ptr<Input> m_input;
    std::shared_ptr<Graphics> m_graphics;

public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void onEnter() = 0;
    virtual void onContinue() {}

    virtual void update() = 0;
    virtual void render() = 0;

    virtual void onSuspend() {}
    virtual void onLeave() = 0;

    virtual void onResize() {}
};


#endif //SHVRD_SCENE_H
