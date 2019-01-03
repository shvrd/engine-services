//
// Created by thekatze on 03/01/2019.
//

#ifndef ENGINITO_EXAMPLESCENE_H
#define ENGINITO_EXAMPLESCENE_H

#include <scenes/Scene.h>
#include <log/Logger.h>

class ExampleScene : public Scene {
public:
    ExampleScene() = default;
    ~ExampleScene() override = default;

    void onEnter() override;
    void onContinue() override;

    void update() override;
    void render() override;

    void onSuspend() override;
    void onLeave() override;
};

void ExampleScene::onEnter() {
    Logger::info("Entering example scene");
}

void ExampleScene::onContinue() {

}

void ExampleScene::update() {

}

void ExampleScene::render() {

}

void ExampleScene::onSuspend() {

}

void ExampleScene::onLeave() {

}

#endif //ENGINITO_EXAMPLESCENE_H
