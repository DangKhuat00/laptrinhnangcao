#include "Window.h"
#include <iostream>

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

Window::Window() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    board = Board(renderer);
    running = true;
    currentPlayer = Player::X;
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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
                displayWinner(winner);
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
    std::string imagePath;
    if (winner == Player::X) {
        imagePath = "img/Xwin.png";
    }
    else if (winner == Player::O) {
        imagePath = "img/Owin.png";
    }
    else if (winner == Player::Draw) {
        imagePath = "img/Draw.png";
    }
    else {
        std::cerr << "Invalid winner" << std::endl;
        return;
    }

    // Load hình ảnh
    SDL_Texture* texture = loadTexture(imagePath);
    if (texture == nullptr) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return;
    }

    // Hiển thị hình ảnh
    SDL_Rect destRect;
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    destRect.x = (SCREEN_WIDTH - destRect.w) / 2;
    destRect.y = (SCREEN_HEIGHT - destRect.h) / 2;
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_RenderPresent(renderer);
}

SDL_Texture* Window::loadTexture(const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        std::cerr << "Failed to load image: " << path << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
