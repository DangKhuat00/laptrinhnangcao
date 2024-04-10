#include "Board.h"
#include <SDL_image.h>
#include <iostream>

Board::Board(SDL_Renderer* renderer) : renderer(renderer) {
    SDL_Surface* boardSurface = IMG_Load("board.png");
    if (!boardSurface) {
        std::cerr << "Failed to load board.png" << std::endl;
        exit(1);
    }
    boardTexture = SDL_CreateTextureFromSurface(renderer, boardSurface);
    SDL_FreeSurface(boardSurface);

    SDL_Surface* xSurface = IMG_Load("X.png");
    if (!xSurface) {
        std::cerr << "Failed to load X.png" << std::endl;
        exit(1);
    }
    xTexture = SDL_CreateTextureFromSurface(renderer, xSurface);
    SDL_FreeSurface(xSurface);

    SDL_Surface* oSurface = IMG_Load("O.png");
    if (!oSurface) {
        std::cerr << "Failed to load O.png" << std::endl;
        exit(1);
    }
    oTexture = SDL_CreateTextureFromSurface(renderer, oSurface);
    SDL_FreeSurface(oSurface);

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = Player::None;
        }
    }
}

void Board::draw() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == Player::X) {
                SDL_Rect destRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, xTexture, NULL, &destRect);
            }
            else if (board[i][j] == Player::O) {
                SDL_Rect destRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, oTexture, NULL, &destRect);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

void Board::placeMarker(int row, int col, Player player) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == Player::None) {
        board[row][col] = player;
    }
}

Player Board::checkWin() {
    // Kiểm tra hàng và cột
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != Player::None && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != Player::None && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Kiểm tra đường chéo
    if (board[0][0] != Player::None && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != Player::None && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // Kiểm tra hòa
    bool draw = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == Player::None) {
                draw = false;
                break;
            }
        }
    }
    if (draw) {
        return Player::None;
    }
    return Player::None;
}
