#include "Window.h"
#include <SDL_image.h>
#include <iostream>
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

Window::Window() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    board = Board(renderer);
    running = true;
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
            board.placeMarker(row, col, Player::X); // Placeholder for now
        }
    }
}

void Window::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    board.draw();
    SDL_RenderPresent(renderer);
}
