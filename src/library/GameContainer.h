#ifndef SHVRDENGINE_GAMECONTAINER_H
#define SHVRDENGINE_GAMECONTAINER_H

#include <future>
#include "util/Timer.h"
#include "threading/ThreadPool.h"
#include "scenes/SceneStack.h"

#include "services/graphics/Graphics.h"
#include "services/input/Input.h"
#include "services/graphics/window/Window.h"
#include "services/audio/Audio.h"

using AtomicBoolean_t = bool;

class GameContainer {
public:
    GameContainer();
    ~GameContainer();

    void start(std::unique_ptr<Scene> initialScene);

    void enterScene(std::unique_ptr<Scene> scene);
    void leaveScene();

    void setTargetFPS(unsigned int fps);
    void setTargetTPS(unsigned int tps);

    ThreadPool& getThreadPool();

private:
    bool initializeSystems();

    void gameLoop();

    void update();
    void render();

    bool isRunning();

    unsigned int getTargetTick();

    ThreadPool m_threadPool;

    AtomicBoolean_t m_initialized;
    SceneStack m_sceneStack;

    Timer m_gameLoopTimer;

    unsigned int m_targetFPS;
    unsigned int m_targetTPS;

    Duration_t m_startTime;
    Duration_t m_frameTime;

    unsigned int m_currentTick;

    // Services
    std::shared_ptr<Window> m_window;
    std::shared_ptr<Input> m_input;
    std::shared_ptr<Graphics> m_graphics;
    std::shared_ptr<Audio> m_audio;
};


#endif //SHVRDENGINE_GAMECONTAINER_H
