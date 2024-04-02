#include "board.h"
#include <iostream>

const int CELL_SIZE = 100; // Độ lớn của mỗi ô trên bảng

Board::Board(SDL_Renderer* renderer) : renderer(renderer), boardTexture(nullptr), xTexture(nullptr), oTexture(nullptr) {}

Board::~Board() {
    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(xTexture);
    SDL_DestroyTexture(oTexture);
}

bool Board::loadMedia() {
    bool success = true;
    SDL_Surface* loadedSurface = nullptr;

    // Load hình ảnh của bảng
    loadedSurface = SDL_LoadBMP("img/Board.png"); // Thay đổi đường dẫn tới hình ảnh của bảng
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image board_image.bmp! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else {
        boardTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (boardTexture == nullptr) {
            std::cerr << "Unable to create texture from board_image.bmp! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        SDL_FreeSurface(loadedSurface);
    }

    // Load hình ảnh của X
    loadedSurface = SDL_LoadBMP("img/X.png"); // Thay đổi đường dẫn tới hình ảnh của X
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image x_image.bmp! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else {
        xTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (xTexture == nullptr) {
            std::cerr << "Unable to create texture from x_image.bmp! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        SDL_FreeSurface(loadedSurface);
    }

    // Load hình ảnh của O
    loadedSurface = SDL_LoadBMP("img/O.png"); // Thay đổi đường dẫn tới hình ảnh của O
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image o_image.bmp! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else {
        oTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (oTexture == nullptr) {
            std::cerr << "Unable to create texture from o_image.bmp! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        SDL_FreeSurface(loadedSurface);
    }

    return success;
}

void Board::print(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Vẽ hình ảnh của bảng
    SDL_Rect boardRect = { 0, 0, CELL_SIZE * BOARD_SIZE, CELL_SIZE * BOARD_SIZE };
    SDL_RenderCopy(renderer, boardTexture, nullptr, &boardRect);

    // Vẽ các hình ảnh X và O lên bảng
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            int x = j * CELL_SIZE;
            int y = i * CELL_SIZE;
            if (board[i][j] == 'X') {
                SDL_Rect xRect = { x, y, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, xTexture, nullptr, &xRect);
            }
            else if (board[i][j] == 'O') {
                SDL_Rect oRect = { x, y, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, oTexture, nullptr, &oRect);
            }
        }
    }
}
