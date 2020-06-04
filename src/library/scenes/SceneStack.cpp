//
// Created by thekatze on 11/12/2018.
//

#include "SceneStack.h"

#include "../log/Logger.h"

#include "../services/InputServiceLocator.h"
#include "../services/GraphicsServiceLocator.h"
#include "../services/WindowServiceLocator.h"
#include "../services/AudioServiceLocator.h"

SceneStack::SceneStack()
    : m_sceneStack() {
    Logger::info("Initializing Scene Stack");
}

void SceneStack::pop() {
    // If current scene isn't the last scene
    if (isEmpty()) {
        return;
    }

    // Leave current scene
    m_sceneStack.top()->onLeave();

    // TODO: This segfaults, find out why
    m_sceneStack.pop();

    // Quit if last scene has been popped
    if (isEmpty()) {
        WindowServiceLocator::get()->requestClose();

        return;
    }

    // Continue previous scene
    m_sceneStack.top()->onContinue();
}

void SceneStack::push(std::unique_ptr<Scene> scene) {
    if (!isEmpty()) {
        // Suspend current scene
        m_sceneStack.top()->onSuspend();
    }

    // Inject services
    scene->m_input = InputServiceLocator::get();
    scene->m_graphics = GraphicsServiceLocator::get();
    scene->m_audio = AudioServiceLocator::get();
    scene->m_sceneStack = std::shared_ptr<SceneStack>(this);

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
    while (!isEmpty()) {
        m_sceneStack.top()->onLeave();
        m_sceneStack.pop();
    }
}

bool SceneStack::isEmpty() {
    return m_sceneStack.empty();
}

void SceneStack::resize() {
    m_sceneStack.top()->onResize(WindowServiceLocator::get()->getDimensions());
}
