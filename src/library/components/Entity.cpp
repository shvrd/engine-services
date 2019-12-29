//
// Created by thekatze on 15/12/2018.
//

#include "Entity.h"

Entity::Entity()
    : m_components()
    , m_finalized(false) {

}

void Entity::update() {
    for (auto& component : m_components) {
        component->update();
    }
}

void Entity::render() {
    for (auto& component : m_components) {
        component->render();
    }
}

void Entity::pushComponent(std::unique_ptr<Component> component) {
    m_components.push_back(std::move(component));
}
