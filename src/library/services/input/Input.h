//
// Created by thekatze on 24/12/2018.
//

#ifndef ENGINITO_INPUT_H
#define ENGINITO_INPUT_H

enum class Key;

class Input {
public:
    Input() = default;
    virtual ~Input() {}

    virtual void update() = 0;

    virtual bool isKeyPressed(Key key) = 0;
    virtual bool isKeyReleased(Key key) = 0;

    virtual int getMouseX() = 0;
    virtual int getMouseY() = 0;

    virtual int getDeltaMouseX() = 0;
    virtual int getDeltaMouseY() = 0;
};

#endif //ENGINITO_INPUT_H
