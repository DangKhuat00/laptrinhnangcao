#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Board.h"
#include "Window.h"
#include "texture.h"



int main(int argc, char* args[]) {
    initSDL();
    loadTextures();

    // Bắt đầu với menu chọn chế độ
    while (currentMode == GameMode::None) {
        drawMenu();
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            handleEvent(event);
        }
    }

    // Khởi động trò chơi
    resetBoard();
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            handleEvent(event);
        }
        if (gameOver) {
            drawContinueScreen();
        }
        else {
            drawBoard();
        }
    }

    closeSDL();
    return 0;
}
