//
// Created by Liam on 03/09/2025.
//

#include "Renderer.h"

Renderer::Renderer() {
    // 1. Initialise SDL
    // SDL_Init needs to be inside an if statement to check if the initialization was successful
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        //return 1;
    }

    // 2. Create a window
    window = SDL_CreateWindow(
        "NES",                  // window title
        SDL_WINDOWPOS_CENTERED, // x position
        SDL_WINDOWPOS_CENTERED, // y position
        800,                    // width
        600,                    // height
        SDL_WINDOW_SHOWN        // flags
    );

    // If the window creation failed, print the error and exit
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        //return 1;
    }

    // 3. Create a renderer
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    // This function creates a renderer for the window, using hardware acceleration and VSync.
    // The -1 indicates that it will use the first available rendering driver.

    // If the renderer creation failed, print the error and exit
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        //return 1;
    }
}

void Renderer::DrawBox(int *position) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, position[0], position[1]);
    std::cout << position[0] << " " << position[1] << std::endl;
}
