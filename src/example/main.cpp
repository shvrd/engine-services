#include <memory>
#include <GameContainer.h>
#include "ExampleScene.h"

int main() {
    GameContainer().start(std::make_unique<ExampleScene>());

    return 0;
}
