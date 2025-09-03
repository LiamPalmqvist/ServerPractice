//
// Created by Liam on 03/09/2025.
//

#ifndef SERVER2_GAME_H
#define SERVER2_GAME_H
#include <iostream>

#include "Renderer.h"

class game {
public:
    std::shared_ptr<Renderer> renderer;

    game();

    int mainLoop();
};


#endif //SERVER2_GAME_H