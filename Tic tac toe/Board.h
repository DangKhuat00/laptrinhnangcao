#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>

const int CELL_SIZE = 100; // Kích thước của mỗi ô

enum class Player { None, X, O };

class Board {
public:
    Board(SDL_Renderer* renderer);
    Board() = default; // Thêm hàm tạo mặc định
    void draw();
    void placeMarker(int row, int col, Player player);
    Player checkWin();

private:
    static const int BOARD_SIZE = 3;
    SDL_Texture* boardTexture;
    SDL_Texture* xTexture;
    SDL_Texture* oTexture;
    Player board[BOARD_SIZE][BOARD_SIZE];
    SDL_Renderer* renderer;
};

#endif
