//
// Created by thekatze on 24/12/2018.
//

#ifndef SHVRD_INPUT_H
#define SHVRD_INPUT_H

#include "../../types/Vector.h"

enum class Key;
enum class MouseButton;

class Input {
public:
    Input() = default;
    virtual ~Input() = default;

    // TODO: Make this inaccessible from outside -> friend class GameContainer
    virtual void update() = 0;

    virtual bool isKeyDown(Key key) = 0;
    virtual bool isKeyPressed(Key key) = 0;
    virtual bool isKeyReleased(Key key) = 0;

    virtual int getMouseX() = 0;
    virtual int getMouseY() = 0;

    virtual int getDeltaMouseX() = 0;
    virtual int getDeltaMouseY() = 0;

    virtual bool isMousePressed(MouseButton mouseButton) = 0;

    virtual const Vector2f getMouseScroll() = 0;
    virtual void setMouseScroll(Vector2f mouseScroll) = 0;
};

#endif //SHVRD_INPUT_H
