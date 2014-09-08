#include "TappyPlane.h"

int main(int argc, char* argv[]) {
    TappyPlane game;

    if (!game.init()) {
        game.freeSystem();
    }

    game.run();

    return 0;
}

