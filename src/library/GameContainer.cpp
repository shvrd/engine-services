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
#include "services/DiagnosticsServiceLocator.h"
#include "services/AudioServiceLocator.h"
#include "services/audio/openal/OpenALAudio.h"

GameContainer::GameContainer()
    : m_initialized(false)
    , m_sceneStack()
    , m_gameLoopTimer()
    , m_targetFPS(0)
    , m_targetTPS(60)
    , m_startTime(0)
    , m_frameTime(0)
    , m_currentTick(0)
    , m_window()
    , m_input()
    , m_graphics()
    , m_audio() {
    // TODO: Dont hardcode target fps/tps
    setTargetFPS(60);
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

    m_startTime = Timer::now();
    this->gameLoop();
}

bool GameContainer::initializeSystems() {
    bool initStatus = true;
    Logger::info("Initializing Systems");

    const int windowWidth = 1600,
              windowHeight = 900;

    // TODO: Load from configuration
    {
        Logger::info("Initializing Window");
        WindowServiceLocator::set(std::make_shared<GLFW_Window>());

        m_window = WindowServiceLocator::get();
        m_window->initialize(windowWidth, windowHeight, "Made with Unity(TM)");

        Logger::info("Initializing Input");
        auto glfwInput = new GLFWInput();
        glfwInput->setGLFWWindow(m_window.get());

        InputServiceLocator::set(std::shared_ptr<GLFWInput>(glfwInput));

        m_input = InputServiceLocator::get();

        Logger::info("Initializing Graphics");
        GraphicsServiceLocator::set(std::make_shared<OpenGLGraphics>());

        m_graphics = GraphicsServiceLocator::get();
        m_graphics->setClearColor(Colors::BLACK);
        m_graphics->initialize(windowWidth, windowHeight);

        DiagnosticsServiceLocator::set(nullptr);

        Logger::info("Initializing Audio");
        AudioServiceLocator::set(std::make_shared<OpenALAudio>());
        m_audio = AudioServiceLocator::get();

        m_audio->initialize();
    }

    return initStatus;
}

void GameContainer::gameLoop() {
    while(this->isRunning()) {
        m_gameLoopTimer.start();

        if (m_window->hasResized()) {
            m_sceneStack.resize();
            m_window->resetResizeFlag();
        }

        this->update();
        this->render();

        int waitTime = m_frameTime - m_gameLoopTimer.get();

        if (waitTime < 0) {
            continue;
        }

        m_gameLoopTimer.wait(static_cast<unsigned int>(waitTime));
    }

    m_sceneStack.clear();
}

void GameContainer::update() {
    unsigned int targetTick = getTargetTick();

    m_window->pollEvents();
    m_input->update();

    while (m_currentTick <= targetTick) {
        m_sceneStack.update();

        ++m_currentTick;
    }
}

void GameContainer::render() {
    m_graphics->clear();
    m_sceneStack.render();
    m_window->swapBuffers();
}

bool GameContainer::isRunning() {
    return !m_window->shouldClose();
}

void GameContainer::setTargetFPS(unsigned int fps) {
    m_targetFPS = fps;
    m_frameTime = TimerUtils::calculateFrameTimeForFPS(fps);
}

void GameContainer::setTargetTPS(unsigned int tps) {
    m_targetTPS = tps;
}

void GameContainer::enterScene(std::unique_ptr<Scene> scene) {
    m_sceneStack.push(std::move(scene));
}

void GameContainer::leaveScene() {
    m_sceneStack.pop();
}

unsigned int GameContainer::getTargetTick() {
    float timePassed = Timer::now() - m_startTime;
    float targetTick = (timePassed * m_targetTPS) / 1000000.f;

    return static_cast<unsigned int>(targetTick);
}
