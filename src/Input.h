//
// Created by Liam on 03/09/2025.
//

#ifndef SERVER2_INPUT_H
#define SERVER2_INPUT_H

#include <SDL2/SDL.h>

enum Key {
    W, S, A, D, ESC, SPACE, UP, DOWN, LEFT, RIGHT, QUIT, LAST
};

enum Mouse {
    BTN_LEFT, BTN_RIGHT, BTN_LAST
};

class Input {
private:
    bool keys[Key::LAST];
    bool buttons[Mouse::BTN_LAST];

public:
    Input();
    ~Input();
    void pollEvents(SDL_Event &event);
    void updateKeys(const SDL_Keycode &, bool);
    bool getQuit() const;
};


#endif //SERVER2_INPUT_H