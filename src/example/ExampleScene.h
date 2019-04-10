//
// Created by thekatze on 03/01/2019.
//

#ifndef ENGINITO_EXAMPLESCENE_H
#define ENGINITO_EXAMPLESCENE_H

#include <scenes/Scene.h>
#include <log/Logger.h>
#include <services/graphics/Sprite.h>

class ExampleScene : public Scene {
    std::unique_ptr<Shader> m_shader;
    std::unique_ptr<Sprite> m_sprite;

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
    : m_shader()
    , m_sprite() {

}

void ExampleScene::onEnter() {
    Logger::info("Entering example scene");
    m_shader = m_graphics->createShader();
    m_shader->setVertexShader("../../../src/library/assets/shaders/basic.vert");
    m_shader->setFragmentShader("../../../src/library/assets/shaders/basic.frag");

    m_shader->finalize();

    m_sprite = m_graphics->createSprite({-.5f, -.5f}, {1.f, 1.f});
}

void ExampleScene::onContinue() {

}

void ExampleScene::update() {

}

void ExampleScene::render() {
    m_shader->bind();
    m_sprite->draw();
    m_shader->unbind();
}

void ExampleScene::onSuspend() {

}

void ExampleScene::onLeave() {

}

#endif //ENGINITO_EXAMPLESCENE_H
