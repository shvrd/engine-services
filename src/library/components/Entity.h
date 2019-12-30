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
    ComponentType* getComponent();

//    template<class ComponentType>
//    void removeComponent();
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

//template<class ComponentType>
//void Entity::removeComponent() {
//    for (auto iterator = m_components.begin(); iterator != m_components.end(); ++iterator) {
//        // Attempt to cast component to given type
//        ComponentType* castedComponent = dynamic_cast<ComponentType*>(*iterator);
//
//        if (castedComponent != nullptr)
//            m_components.erase(iterator);
//    }
//}

#endif //SHVRD_ENTITY_H
