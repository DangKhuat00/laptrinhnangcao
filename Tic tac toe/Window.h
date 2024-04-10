#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <string> // Thêm thư viện này
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
    void displayWinner(Player winner);
    SDL_Texture* loadTexture(const std::string& path); // Sửa đổi đối số của hàm này
};

#endif
