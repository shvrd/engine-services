#include "GameContainer.h"

#include "log/Logger.h"
#include "util/TimerUtils.h"

// OpenGL Graphics needs to be included before GLFW, since glew.h needs to be included before gl.h, which is internally included in GLFW
#include "services/graphics/opengl/OpenGLGraphics.h"

#include "services/WindowServiceLocator.h"
#include "services/graphics/window/GLFW_Window.h"
#include "services/input/GLFWInput.h"
#include "services/InputServiceLocator.h"
#include "services/GraphicsServiceLocator.h"

GameContainer::GameContainer()
    : m_threadPool(1)
    , m_sceneStack()
    , m_gameLoopTimer()
    // TODO: Dont hardcode target fps
    , m_frameTime(TimerUtils::calculateFrameTimeForFPS(60))
    , m_window()
    , m_input() {
    m_initialized = this->initializeSystems();
}

GameContainer::~GameContainer() = default;

void GameContainer::start(std::unique_ptr<Scene> initialScene) {
    // Quit if initialization failed
    if (!this->m_initialized) {
        Logger::error("Failed to initialize systems, exiting");

        return;
    }

    Logger::info("Initialization finished in " + std::to_string(m_gameLoopTimer.get() / 1000) + "ms");
    Logger::info("Starting game loop");

    m_sceneStack.push(std::move(initialScene));

    this->gameLoop();
}

bool GameContainer::initializeSystems() {
    bool initStatus = true;
    Logger::info("Initializing systems");

    const int windowWidth = 1600,
              windowHeight = 900;

    // TODO: Load from configuration
    {
        Logger::info("Initializing Window");
        WindowServiceLocator::set(std::make_shared<GLFW_Window>());

        m_window = WindowServiceLocator::get();
        m_window->initialize(windowWidth, windowHeight, "Enginito");

        Logger::info("Initializing Input");
        auto glfwInput = new GLFWInput();
        glfwInput->setGLFWWindow(WindowServiceLocator::get().get());

        InputServiceLocator::set(std::shared_ptr<GLFWInput>(glfwInput));

        m_input = InputServiceLocator::get();

        Logger::info("Initializing Graphics");
        GraphicsServiceLocator::set(std::make_shared<OpenGLGraphics>());

        m_graphics = GraphicsServiceLocator::get();
        m_graphics->setClearColor({0, 0, 0, 1});
        m_graphics->initialize(windowWidth, windowHeight);
    }

    return initStatus;
}

void GameContainer::gameLoop() {
    while(this->isRunning()) {
        m_gameLoopTimer.start();
        this->update();
        this->render();

        m_window->pollEvents();

        //TODO: Make updates not dependent on framerate -> Target TPS (ticks per second)
        int waitTime = m_frameTime - m_gameLoopTimer.get();

        if (waitTime < 0) {
            continue;
        }

        m_gameLoopTimer.wait(static_cast<unsigned int>(waitTime));
    }

    m_sceneStack.clear();
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

void GameContainer::enterScene(std::unique_ptr<Scene> scene) {
    m_sceneStack.push(std::move(scene));
}

void GameContainer::leaveScene() {
    m_sceneStack.pop();
}
