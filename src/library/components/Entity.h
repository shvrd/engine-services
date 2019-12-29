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

    template<class ComponentType, class... Args>
    void addComponent(Args&&... args);

    void pushComponent(std::unique_ptr<Component> component);

    template<class ComponentType>
    std::unique_ptr<ComponentType> removeComponent();

    template<class ComponentType>
    ComponentType* getComponent();

};

template<class ComponentType>
ComponentType* Entity::getComponent() {
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
    m_components.emplace_back(std::make_unique<ComponentType>(args...));
    m_components.back()->m_parent = this;
}

template<class ComponentType>
std::unique_ptr<ComponentType> Entity::removeComponent() {
    // TODO: Make component be returned
    // TODO: This segfaults when deleting something the second time, unique pointer points to 0xbaadf00d
    std::unique_ptr<ComponentType> removedComponent = nullptr;

    auto componentIterator = m_components.begin();

    while (componentIterator != m_components.end()) {
        // Attempt to cast component to given type
        ComponentType* castedComponent = dynamic_cast<ComponentType*>(componentIterator->get());

        if (castedComponent != nullptr) {
            m_components.erase(componentIterator);
        }

        componentIterator++;
    }

    return removedComponent;
}

#endif //SHVRD_ENTITY_H
