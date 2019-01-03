//
// Created by thekatze on 11/12/2018.
//

#ifndef GENERIC_LIBRARY_SCENESTACK_H
#define GENERIC_LIBRARY_SCENESTACK_H

#include <stack>
#include <memory>
#include "Scene.h"

using SceneStack_t = std::stack<std::unique_ptr<Scene>>;

class SceneStack {
public:
    SceneStack();
    ~SceneStack() = default;

    void push(std::unique_ptr<Scene> scene);
    void pop();

    void update();
    void render();

    void clear();
private:
    SceneStack_t m_sceneStack;
};


#endif //GENERIC_LIBRARY_SCENESTACK_H
