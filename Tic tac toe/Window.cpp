#include "Window.h"
#include <iostream>
#include<SDL_image.h>
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

Window::Window() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    board = Board(renderer);
    running = true;
    currentPlayer = Player::X;
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Window::run() {
    while (running) {
        handleEvents();
        render();
    }
}

void Window::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            int row = mouseY / CELL_SIZE;
            int col = mouseX / CELL_SIZE;
            if (currentPlayer == Player::X) {
                board.placeMarker(row, col, Player::X);
                currentPlayer = Player::O;
            }
            else {
                board.placeMarker(row, col, Player::O);
                currentPlayer = Player::X;
            }
            Player winner = board.checkWin();
            if (winner != Player::None) {
                displayWinner(winner); // Hiển thị người chiến thắng
            }
        }
    }
}

void Window::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    board.draw();
    SDL_RenderPresent(renderer);
}

void Window::displayWinner(Player winner) {
    SDL_Surface* surface;
    if (winner == Player::X) {
        surface = IMG_Load("img/Xwin.png");
    }
    else if (winner == Player::O) {
        surface = IMG_Load("img/Owin.png");
    }
    else {
        surface = IMG_Load("img/Draw.png");
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect destRect;
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    destRect.x = (SCREEN_WIDTH - destRect.w) / 2;
    destRect.y = (SCREEN_HEIGHT - destRect.h) / 2;

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(2000); // Chờ 2 giây trước khi thoát
    running = false;
}
