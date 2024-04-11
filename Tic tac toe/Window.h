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
    Player currentPlayer;
    void handleEvents();
    void render();
    void displayWinner(Player winner); // Thêm hàm hiển thị người chiến thắng
};

#endif
