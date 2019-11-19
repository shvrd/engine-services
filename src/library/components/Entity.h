//
// Created by thekatze on 15/12/2018.
//

#ifndef SHVRD_ENTITY_H
#define SHVRD_ENTITY_H

#include <memory>
#include <vector>

#include "Component.h"
#include "../log/Logger.h"

class Entity {
    // TODO: Maybe optimize cache usage
    std::vector<std::unique_ptr<Component>> m_components;

    bool m_finalized;
public:
    Entity();
    ~Entity() = default;

    void update();
    void render();

    void finalize();

    template<class ComponentType, class... Args>
    void addComponent(Args&&... args);

    template<class ComponentType>
    ComponentType* getComponent();

};

template<class ComponentType>
ComponentType* Entity::getComponent() {
    if (m_finalized) {
        Logger::warn("Cannot get component from non-finalized entity");

        return nullptr;
    }

    for (auto& component : m_components) {
        // Attempt to cast component to given type
        ComponentType* castedComponent = dynamic_cast<ComponentType*>(component.get());

        if (castedComponent != nullptr)
            return castedComponent;
    }

    return nullptr;
}

template<class ComponentType, class... Args>
void Entity::addComponent(Args&&... args) {
    if (m_finalized) {
        Logger::warn("Cannot add component to finalized entity");

        return;
    }

    m_components.emplace_back(std::make_unique<ComponentType>(args...));
    m_components.back()->m_parent = this;
}

#endif //SHVRD_ENTITY_H
