//
// Created by thekatze on 15/12/2018.
//

#ifndef GENERIC_LIBRARY_COMPONENT_H
#define GENERIC_LIBRARY_COMPONENT_H

// Forward declare entity due to circular dependency.
class Entity;

class Component {
    // To get reference from parent
    friend class Entity;
    Entity* m_parent;

public:
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    inline Entity* getParent() { return m_parent; }
};

#endif //GENERIC_LIBRARY_COMPONENT_H
