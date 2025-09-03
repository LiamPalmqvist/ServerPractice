//
// Created by Liam on 03/09/2025.
//

#include "game.h"

game::game() {
    renderer = std::make_shared<Renderer>();
};

int game::mainLoop() {
    // 4. Main loop
    bool running = true;
    SDL_Event event;
    while (running) {
        // process events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // exit the loop if the window is closed
            }
        }

        // Render something (black background)
        SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, 255); // RGB + Alpha
        SDL_RenderClear(renderer->renderer); // Clear the screen with the draw colour
        SDL_RenderPresent(renderer->renderer); // Present the renderer to the screen
    }

    // 5. Cleanup
    SDL_DestroyRenderer(renderer->renderer); // Destroy the renderer
    SDL_DestroyWindow(renderer->window); // Destroy the window
    SDL_Quit(); // Quit SDL
    return 0;
}