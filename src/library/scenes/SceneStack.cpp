//
// Created by thekatze on 11/12/2018.
//

#include "SceneStack.h"
#include "EmptyScene.h"
#include "../log/Logger.h"
#include "../services/InputServiceLocator.h"
#include "../services/GraphicsServiceLocator.h"

SceneStack::SceneStack()
    : m_sceneStack() {
    Logger::info("Initializing Scene Stack with empty scene");
    m_sceneStack.push(std::make_unique<EmptyScene>());
}

void SceneStack::pop() {
    // If current scene isn't the last non-empty scene
    if (m_sceneStack.size() <= 1) {
        return;
    }

    // Leave current scene
    m_sceneStack.top()->onLeave();
    m_sceneStack.pop();

    // Continue previous scene
    m_sceneStack.top()->onContinue();
}

void SceneStack::push(std::unique_ptr<Scene> scene) {
    // Suspend current scene
    m_sceneStack.top()->onSuspend();

    // Inject services
    scene->m_input = InputServiceLocator::get();
    scene->m_graphics = GraphicsServiceLocator::get();

    // Enter new scene
    scene->onEnter();
    m_sceneStack.push(std::move(scene));
}

void SceneStack::update() {
    m_sceneStack.top()->update();
}

void SceneStack::render() {
    m_sceneStack.top()->render();
}

void SceneStack::clear() {
    while (!m_sceneStack.empty()) {
        m_sceneStack.top()->onLeave();
        m_sceneStack.pop();
    }
}
