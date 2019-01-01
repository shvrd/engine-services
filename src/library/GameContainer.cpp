#include "GameContainer.h"

#include "log/Logger.h"
#include "util/TimerUtils.h"

#include "services/WindowServiceLocator.h"
#include "services/graphics/window/GLFW_Window.h"
#include "services/input/GLFWInput.h"
#include "services/InputServiceLocator.h"
#include "services/GraphicsServiceLocator.h"
#include "services/graphics/OpenGLGraphics.h"

GameContainer::GameContainer()
    : m_threadPool(ThreadPool::getSystemThreads() - 1)
    , m_sceneStack()
    , m_gameLoopTimer()
    , m_frameTime(TimerUtils::calculateFrameTimeForFPS(60))
    , m_window()
    , m_input() {
    // m_initialized = m_threadPool.enqueue([this]() -> bool {
    //     return
            this->initializeSystems();
    // });
}

GameContainer::~GameContainer() = default;

void GameContainer::start() {
    // Quit if initialization failed
    if (!this->m_initialized.get()) {
        Logger::error("Failed to initialize systems, exiting");

        return;
    }

    Logger::info("Initialization finished in " + std::to_string(m_gameLoopTimer.get() / 1000) + "ms");
    Logger::info("Starting game loop");
    this->gameLoop();
}

bool GameContainer::initializeSystems() {
    bool initStatus = true;
    Logger::info("Initializing systems");

    // TODO: Load from configuration
    {
        WindowServiceLocator::set(std::make_shared<GLFW_Window>());

        m_window = WindowServiceLocator::get();
        m_window->initialize(800, 600, "Enginito");

        GLFWInput* glfwInput = new GLFWInput();
        glfwInput->setGLFWWindow(dynamic_cast<GLFW_Window*>(m_window.get())->getWindow());

        InputServiceLocator::set(std::shared_ptr<GLFWInput>(glfwInput));

        m_input = InputServiceLocator::get();

        GraphicsServiceLocator::set(std::make_shared<OpenGLGraphics>());

        m_graphics = GraphicsServiceLocator::get();
        m_graphics->setClearColor();
    }

    return initStatus;
}

void GameContainer::gameLoop() {
    while(this->isRunning()) {
        m_gameLoopTimer.start();
        this->update();
        this->render();

        m_window->pollEvents();

        int waitTime = m_frameTime - m_gameLoopTimer.get();

        if (waitTime < 0) {
            Logger::warn("Target frame rate could not be reached");

            continue;
        }

        m_gameLoopTimer.wait(waitTime);
    }
}

void GameContainer::update() {
    m_input->update();
    m_sceneStack.update();
}

void GameContainer::render() {
    m_graphics->clear();
    m_sceneStack.render();
    m_window->swapBuffers();
}

ThreadPool& GameContainer::getThreadPool() {
    return m_threadPool;
}

bool GameContainer::isRunning() {
    return !m_window->windowShouldClose();
}

void GameContainer::setTargetFPS(unsigned int fps) {
    m_frameTime = TimerUtils::calculateFrameTimeForFPS(fps);
}
