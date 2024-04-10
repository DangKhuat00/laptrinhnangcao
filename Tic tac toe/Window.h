#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "Board.h"

class Window {
public:
    Window();
    ~Window();
    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Board board;
    bool running;

    void handleEvents();
    void render();
};

#endif
