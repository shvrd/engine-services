//
// Created by thekatze on 03/01/2019.
//

#ifndef ENGINITO_EXAMPLESCENE_H
#define ENGINITO_EXAMPLESCENE_H

#include <scenes/Scene.h>
#include <log/Logger.h>
#include <services/graphics/Sprite.h>
#include <services/input/GLFWInput.h>

class ExampleScene : public Scene {
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Sprite> m_sprite;

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
    m_shader->setVertexShader("../../../src/library/assets/shaders/sprite.vert");
    m_shader->setFragmentShader("../../../src/library/assets/shaders/sprite.frag");

    m_shader->addAttribute("vertexPosition");
    m_shader->addAttribute("vertexColor");
    m_shader->addAttribute("vertexUV");

    m_shader->finalize();

    m_sprite = m_graphics->createSprite({0.f, 0.f}, {100.f, 100.f});
    m_sprite->setTexture(m_graphics->loadTexture("../../../src/library/assets/textures/dev.png"));
}

void ExampleScene::onContinue() {

}

void ExampleScene::update() {
    float speed = 4.f;

    if (m_input->isKeyPressed(Key::LEFT_SHIFT)) {
        speed *= 4;
    }

    if (m_input->isKeyPressed(Key::LEFT_CONTROL)) {
        speed /= 2;
    }

    if (m_input->isMousePressed(MouseButton::LEFT)) {
        m_graphics->getCamera()->translate({(float) -m_input->getDeltaMouseX(), 0.f});
        m_graphics->getCamera()->translate({0.f, (float) m_input->getDeltaMouseY()});
    }

    if (m_input->isKeyPressed(Key::W)) {
        m_graphics->getCamera()->translate({0.f, -speed});
    }
    if (m_input->isKeyPressed(Key::S)) {
        m_graphics->getCamera()->translate({0.f, speed});
    }
    if (m_input->isKeyPressed(Key::A)) {
        m_graphics->getCamera()->translate({speed, .0f});
    }
    if (m_input->isKeyPressed(Key::D)) {
        m_graphics->getCamera()->translate({-speed, .0f});
    }

    if (m_input->isKeyPressed(Key::E)) {
        m_graphics->getCamera()->scale(1.1f);
    }
    if (m_input->isKeyPressed(Key::Q)) {
        m_graphics->getCamera()->scale(.9f);
    }

    if (m_input->isKeyPressed(Key::Y)) {
        m_graphics->getCamera()->rotate(1.f);
    }
    if (m_input->isKeyPressed(Key::C)) {
        m_graphics->getCamera()->rotate(-1.f);
    }

    static bool buttonDown = false;

    if (m_input->isKeyPressed(Key::F10)) {
        if (!buttonDown) {
            m_shader->reload();
        }
    }

    buttonDown = m_input->isKeyPressed(Key::F10);
}

void ExampleScene::render() {
    m_graphics->bindShader(m_shader);
    m_graphics->useTexture(m_sprite->getTexture());
    m_sprite->draw();
    m_shader->unbind();

    m_graphics->drawText("sphinx of black quartz, judge my vow", {0, -100});
    m_graphics->drawText("SPHINX OF BLACK QUARTZ, JUDGE MY VOW", {0, -200});
}

void ExampleScene::onSuspend() {

}

void ExampleScene::onLeave() {

}

#endif //ENGINITO_EXAMPLESCENE_H
