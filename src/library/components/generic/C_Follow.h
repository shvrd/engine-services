//
// Created by thekatze on 29/12/2019.
//

#ifndef SHVRD_C_FOLLOW_H
#define SHVRD_C_FOLLOW_H

#include "../Component.h"
#include "../Entity.h"
#include "../../types/Vector.h"
#include "C_Transform.h"

class C_Follow : public Component {
    Entity* m_leader;

public:
    C_Follow(Entity* leader, const Vector2f &offset);
    ~C_Follow() = default;

    void update() override;

    Vector2f m_offset;
};

C_Follow::C_Follow(Entity* leader, const Vector2f &offset = {})
    : m_leader(leader)
    , m_offset(offset) {}

void C_Follow::update() {
    C_Transform* thisTransform = getParent()->getComponent<C_Transform>();
    C_Transform* leaderTransform = m_leader->getComponent<C_Transform>();

    if (thisTransform && leaderTransform) {
        thisTransform->m_location = leaderTransform->m_location + m_offset;
    }
}

#endif //SHVRD_C_FOLLOW_H
