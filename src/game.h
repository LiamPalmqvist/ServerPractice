//
// Created by Liam on 03/09/2025.
//

#ifndef SERVER2_GAME_H
#define SERVER2_GAME_H
#include <iostream>

#include "Renderer.h"
#include "Input.h"

class game {
public:
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<Input> input;
    int position[2] = { 0, 0 };
    game();

    int mainLoop();
};


#endif //SERVER2_GAME_H