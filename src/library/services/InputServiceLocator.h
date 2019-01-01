//
// Created by thekatze on 24/12/2018.
//

#ifndef ENGINITO_INPUTSERVICELOCATOR_H
#define ENGINITO_INPUTSERVICELOCATOR_H

#include <memory>
#include "input/Input.h"
#include "input/NullInput.h"

class InputServiceLocator {
    static std::shared_ptr<Input> m_input;
public:

    static std::shared_ptr<Input> get();

    static void set(std::shared_ptr<Input> input);
};

#endif //ENGINITO_INPUTSERVICELOCATOR_H
