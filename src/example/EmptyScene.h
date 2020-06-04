//
// Created by thekatze on 04/06/2020.
//

#ifndef SHVRD_EMPTYSCENE_H
#define SHVRD_EMPTYSCENE_H

#include <scenes/Scene.h>

class EmptyScene : public Scene {
public:
    EmptyScene() = default;
    ~EmptyScene() override = default;

    void onEnter() override;
    void onContinue() override;

    void update() override;
    void render() override;

    void onSuspend() override;
    void onLeave() override;

    void onResize(const Vector2f& windowSize) override;
};

void EmptyScene::onEnter() {

}

void EmptyScene::onContinue() {
    Scene::onContinue();
}

void EmptyScene::update() {
    if (m_input->isKeyPressed(Key::Z)) {
        m_sceneStack->pop();
    }
}

void EmptyScene::render() {

}

void EmptyScene::onSuspend() {
    Scene::onSuspend();
}

void EmptyScene::onLeave() {

}

void EmptyScene::onResize(const Vector2f &windowSize) {
    Scene::onResize(windowSize);
}

#endif //SHVRD_EMPTYSCENE_H
