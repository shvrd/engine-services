//
// Created by thekatze on 11/12/2018.
//

#ifndef GENERIC_LIBRARY_EMPTYSCENE_H
#define GENERIC_LIBRARY_EMPTYSCENE_H

#include "Scene.h"
#include "../log/Logger.h"

class EmptyScene : public Scene {
public:

    ~EmptyScene() = default;

    void onEnter() override {

    }

    void onContinue() override {

    }

    void update() override {

    }

    void render() override {

    }

    void onSuspend() override {

    }

    void onLeave() override {

    }
};

#endif //GENERIC_LIBRARY_EMPTYSCENE_H
