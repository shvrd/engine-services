//
// Created by thekatze on 15/12/2018.
//

#include "Entity.h"

void Entity::finalize() {
    m_finalized = true;
}

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
