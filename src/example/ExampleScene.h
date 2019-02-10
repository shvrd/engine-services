//
// Created by thekatze on 03/01/2019.
//

#ifndef ENGINITO_EXAMPLESCENE_H
#define ENGINITO_EXAMPLESCENE_H

#include <scenes/Scene.h>
#include <log/Logger.h>

class ExampleScene : public Scene {
    std::unique_ptr<Shader> m_shader;
public:
    ExampleScene();
    ~ExampleScene() override = default;

    void onEnter() override;
    void onContinue() override;

    void update() override;
    void render() override;

    void onSuspend() override;
    void onLeave() override;
};

ExampleScene::ExampleScene()
    : m_shader() {

}

void ExampleScene::onEnter() {
    Logger::info("Entering example scene");
    m_shader = m_graphics->createShader();
    m_shader->setVertexShader("../../../src/library/assets/shaders/basic.vert");
    m_shader->setFragmentShader("../../../src/library/assets/shaders/basic.frag");
}

void ExampleScene::onContinue() {

}

void ExampleScene::update() {

}

void ExampleScene::render() {
    m_shader->bind();

    m_shader->unbind();
}

void ExampleScene::onSuspend() {

}

void ExampleScene::onLeave() {

}

#endif //ENGINITO_EXAMPLESCENE_H
