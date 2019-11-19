//
// Created by thekatze on 15/12/2018.
//

#ifndef SHVRD_COMPONENT_H
#define SHVRD_COMPONENT_H

// Forward declare entity due to circular dependency.
class Entity;

class Component {
    // To get reference from parent
    friend class Entity;
    Entity* m_parent;

public:
    virtual void update() {};
    virtual void render() {};

protected:
    inline Entity* getParent() { return m_parent; }
};

#endif //SHVRD_COMPONENT_H
