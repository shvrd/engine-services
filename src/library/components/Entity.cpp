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
