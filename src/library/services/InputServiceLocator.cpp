//
// Created by thekatze on 24/12/2018.
//

#include "InputServiceLocator.h"

std::shared_ptr<Input> InputServiceLocator::m_input = std::make_shared<NullInput>();

std::shared_ptr<Input> InputServiceLocator::get() {
    return m_input;
}

void InputServiceLocator::set(std::shared_ptr<Input> input) {
    if (input == nullptr) {
        m_input = std::make_shared<NullInput>();

        return;
    }

    m_input = input;
}
