//
// Created by Liam on 03/09/2025.
//

#ifndef SERVER2_RENDERER_H
#define SERVER2_RENDERER_H
#include <SDL2/SDL.h>
#include <iostream>

class Renderer {
public:
    SDL_Window *window;
    SDL_Renderer *renderer;

    Renderer();

    void DrawBox(int *position);
};


#endif //SERVER2_RENDERER_H