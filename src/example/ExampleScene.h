//
// Created by thekatze on 03/01/2019.
//

#ifndef SHVRD_EXAMPLESCENE_H
#define SHVRD_EXAMPLESCENE_H

#include <scenes/Scene.h>
#include <log/Logger.h>
#include <services/graphics/Sprite.h>
#include <services/input/GLFWInput.h>
#include <components/Entity.h>
#include "C_Renderable.h"
#include "C_Transform.h"
#include "C_PlayerController.h"
#include "C_TileMap.h"
#include "C_TileMapRenderable.h"

class ExampleScene : public Scene {
    std::vector<std::unique_ptr<Entity>> m_entities;
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

ExampleScene::ExampleScene() = default;

void ExampleScene::onEnter() {
    std::unique_ptr<Entity> player = std::make_unique<Entity>();
    std::unique_ptr<Entity> player2 = std::make_unique<Entity>();

    std::unique_ptr<Entity> tileMap = std::make_unique<Entity>();

    auto shader = m_graphics->createShader();
    shader->addAttribute("vertexPosition");
    shader->addAttribute("vertexColor");
    shader->addAttribute("vertexUV");

    shader->setVertexShader("../../../src/library/assets/shaders/sprite.vert");
    shader->setFragmentShader("../../../src/library/assets/shaders/sprite.frag");

    shader->finalize();

    auto sprite = m_graphics->createSprite({-50, -50}, {100, 100});
    sprite->setTexture(m_graphics->loadTexture("../../../src/library/assets/textures/dev.png"));

    player->addComponent<C_Renderable>(shader, sprite);
    player->addComponent<C_Transform>(Vector2f{0, 0});
    // player->addComponent<C_PlayerController>(m_input);

    player2->addComponent<C_Renderable>(shader, sprite);
    player2->addComponent<C_Transform>(Vector2f{100, 100});

    // Tilemap stuff
    tileMap->addComponent<C_TileMap>(80, 40);

    C_TileMap* tileMapComponent = tileMap->getComponent<C_TileMap>();

    for (unsigned int x = 0; x < tileMapComponent->getWidth(); ++x) {
        for (unsigned int y = 0; y < tileMapComponent->getHeight(); ++y) {
            tileMapComponent->setTileAt(x, y, {1, nullptr, false});
        }
    }

    tileMap->addComponent<C_TileMapRenderable>(shader);

    m_entities.push_back(std::move(player));
    m_entities.push_back(std::move(player2));

    m_entities.push_back(std::move(tileMap));
}

void ExampleScene::onContinue() {

}

void ExampleScene::update() {
    for (auto& entity : m_entities) {
        entity->update();
    }

    float speed = 4.f;

    if (m_input->isKeyPressed(Key::LEFT_SHIFT)) {
        speed *= 4;
    }

    if (m_input->isKeyPressed(Key::LEFT_CONTROL)) {
        speed /= 2;
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
}

void ExampleScene::render() {
    for (auto& entity : m_entities) {
        entity->render();
    }
}

void ExampleScene::onSuspend() {

}

void ExampleScene::onLeave() {

}

#endif //SHVRD_EXAMPLESCENE_H

/*
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
 */

/*
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

    if (m_input->getMouseScroll().y > 0) {
        m_graphics->getCamera()->scale(1.2f);
    } else if (m_input->getMouseScroll().y < 0) {
        m_graphics->getCamera()->scale(0.8f);
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
 */

/*
    m_graphics->bindShader(m_shader);
    m_graphics->useTexture(m_sprite->getTexture());
    m_sprite->draw();
    m_shader->unbind();

    m_graphics->drawText("sphinx of black quartz, judge my vow", {0, -100});
    m_graphics->drawText("SPHINX OF BLACK QUARTZ, JUDGE MY VOW", {0, -200});
 */