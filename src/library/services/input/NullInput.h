//
// Created by thekatze on 24/12/2018.
//

#ifndef ENGINITO_NULLINPUT_H
#define ENGINITO_NULLINPUT_H

#include "Input.h"

class NullInput : public Input {
    Vector2f m_nullVector = {};
public:
    NullInput() = default;
    ~NullInput() override = default;

    void update() override {}

    bool isKeyPressed(Key key) override { return false; }
    bool isKeyReleased(Key key) override { return true; }

    int getMouseX() override { return 0; }
    int getMouseY() override { return 0; }

    int getDeltaMouseX() override { return 0; }
    int getDeltaMouseY() override { return 0; }

    bool isMousePressed(MouseButton mouseButton) override { return false; }

    const Vector2f getMouseScroll() override { return m_nullVector; }
    void setMouseScroll(Vector2f mouseScroll) override {}
};


#endif //ENGINITO_NULLINPUT_H
