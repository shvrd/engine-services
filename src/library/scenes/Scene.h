//
// Created by thekatze on 11/12/2018.
//

#ifndef GENERIC_LIBRARY_SCENE_H
#define GENERIC_LIBRARY_SCENE_H

class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void onEnter() = 0;
    virtual void onContinue() {}

    virtual void update() = 0;
    virtual void render() = 0;

    virtual void onSuspend() {}
    virtual void onLeave() = 0;
};


#endif //GENERIC_LIBRARY_SCENE_H
