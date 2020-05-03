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
    m_sceneStack.pop();

    // TODO: GRACEFULLY Quit if scene stack is empty.
    if (isEmpty()) {
        Logger::critical("Popped last scene off SceneStack, quitting.", 10);
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
