//
// Created by Liam on 03/09/2025.
//

#include "game.h"

game::game() {
    renderer = std::make_shared<Renderer>();
    input = std::make_shared<Input>();
    // This is the game logic part of the file

};

int game::mainLoop() {
    // 4. Main loop
    bool running = true;
    SDL_Event event;
    while (running) {
        input->pollEvents(event);
        if (input->getBtn(ESC)) running = false;

        if (input->getBtn(W)) {
            position[1]--;
        }
        if (input->getBtn(A)) {
            position[0]--;
        }
        if (input->getBtn(S)) {
            position[1]++;
        }
        if (input->getBtn(D)) {
            position[0]++;
        }
        // Render something (black background)
        SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, 255); // RGB + Alpha
        SDL_RenderClear(renderer->renderer); // Clear the screen with the draw colour
        renderer->DrawBox(position);
        SDL_RenderPresent(renderer->renderer); // Present the renderer to the screen
    }

    // 5. Cleanup
    SDL_DestroyRenderer(renderer->renderer); // Destroy the renderer
    SDL_DestroyWindow(renderer->window); // Destroy the window
    SDL_Quit(); // Quit SDL
    return 0;
}