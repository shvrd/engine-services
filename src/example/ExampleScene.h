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
#include <services/WindowServiceLocator.h>
#include "C_Renderable.h"
#include "C_Transform.h"
#include "C_PlayerController.h"
#include "C_TileMap.h"
#include "C_TileMapRenderable.h"
#include "TileMapLoader.h"
#include "C_Camera.h"
#include "C_Follow.h"

class ExampleScene : public Scene {
    std::vector<std::unique_ptr<Entity>> m_entities;

    Entity* m_player = nullptr;
    Entity* m_camera = nullptr;
public:
    ExampleScene();
    ~ExampleScene() override = default;

    void onEnter() override;
    void onContinue() override;

    void update() override;
    void render() override;

    void onSuspend() override;
    void onLeave() override;

    void onResize(const Vector2f& windowSize) override;
};

ExampleScene::ExampleScene() = default;

void ExampleScene::onEnter() {
    std::unique_ptr<Entity> player = std::make_unique<Entity>();
    std::unique_ptr<Entity> camera = std::make_unique<Entity>();

    std::unique_ptr<Entity> tileMap = std::make_unique<Entity>();

    auto shader = m_graphics->createShader();
    shader->addAttribute("vertexPosition");
    shader->addAttribute("vertexColor");
    shader->addAttribute("vertexUV");

    shader->setVertexShader("assets/shaders/sprite.vert");
    shader->setFragmentShader("assets/shaders/sprite.frag");

    shader->finalize();

    auto sprite = std::make_shared<Sprite>(Sprite({-50, -50}, {100, 100}));
    sprite->setTexture(m_graphics->loadTexture("assets/textures/dev.png"));

    player->addComponent<C_Renderable>(shader, sprite);
    player->addComponent<C_Transform>(Vector2f{0, 0}, 0.f, 1.f);
    player->addComponent<C_PlayerController>(m_input);

    m_player = player.get();

    camera->addComponent<C_Transform>();
    camera->addComponent<C_Follow>(player.get(), Vector2f{-800, -450});
    camera->addComponent<C_Camera>();

    m_camera = camera.get();

    tileMap->pushComponent(TileMapLoader::loadTileMap("assets/maps/test.map"));

    tileMap->addComponent<C_TileMapRenderable>(shader);

    m_entities.push_back(std::move(player));
    m_entities.push_back(std::move(camera));

    m_entities.push_back(std::move(tileMap));
}

void ExampleScene::onContinue() {

}

void ExampleScene::update() {
    for (auto& entity : m_entities) {
        entity->update();
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

void ExampleScene::onResize(const Vector2f& windowSize) {
    Logger::info("Resized to X: " + std::to_string(windowSize.x) + " Y: " + std::to_string(windowSize.y));

    m_camera->removeComponent<C_Follow>();
    m_camera->addComponent<C_Follow>(m_player, Vector2f{-windowSize.x / 2, -windowSize.y / 2});
}

#endif //SHVRD_EXAMPLESCENE_H
