//
// Created by Liam on 03/09/2025.
//

#include "Input.h"

Input::Input() {
    for (int i = 0; i < Key::LAST; i++) {
        keys[i] = false;
    }
    buttons[Mouse::BTN_LEFT] = false;
    buttons[Mouse::BTN_RIGHT] = false;
}

Input::~Input() {}

void Input::pollEvents(SDL_Event &event) {
    while (SDL_PollEvent(&event)) {
        if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0) {
            updateKeys(event.key.keysym.sym, event.type == SDL_KEYDOWN);
        }

        if (event.type == SDL_QUIT) {
            keys[QUIT] = true;
        }

        buttons[Mouse::BTN_LEFT]  = (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
        buttons[Mouse::BTN_RIGHT] = (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
    }
}

void Input::updateKeys(const SDL_Keycode &key, bool keyDown) {
    Key index;

    switch (key) {
        case SDLK_RIGHT:	index = Key::RIGHT; break;
        case SDLK_d:		index = Key::D; break;
        case SDLK_LEFT:		index = Key::LEFT; break;
        case SDLK_a:		index = Key::A; break;
        case SDLK_UP:		index = Key::UP; break;
        case SDLK_w:		index = Key::W; break;
        case SDLK_DOWN:		index = Key::DOWN; break;
        case SDLK_s:		index = Key::S; break;
        case SDLK_ESCAPE:	index = Key::ESC; break;
        case SDLK_SPACE:	index = Key::SPACE; break;
        default:
            return;	// we don't care about other keys, at least now
    }

    keys[index] = keyDown;
}

bool Input::getQuit() const {
    return keys[QUIT] || keys[ESC];
}
