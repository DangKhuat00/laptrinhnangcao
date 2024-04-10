#include "Board.h"

Board::Board(SDL_Renderer* renderer) : renderer(renderer) {
    // Khởi tạo tất cả các ô trống
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = Player::None;
        }
    }
}

void Board::draw() {
    // Vẽ bảng Tic Tac Toe
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 1; i < BOARD_SIZE; ++i) {
        SDL_RenderDrawLine(renderer, i * CELL_SIZE, 0, i * CELL_SIZE, CELL_SIZE * BOARD_SIZE);
        SDL_RenderDrawLine(renderer, 0, i * CELL_SIZE, CELL_SIZE * BOARD_SIZE, i * CELL_SIZE);
    }

    // Vẽ các đánh dấu X và O
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == Player::X) {
                // Vẽ X
            }
            else if (board[i][j] == Player::O) {
                // Vẽ O
            }
        }
    }
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
        return Player::Draw;
    }

    return Player::None;
}
