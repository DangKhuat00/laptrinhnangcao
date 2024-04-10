#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;
const int CELL_SIZE = SCREEN_WIDTH / 3; // Giả sử kích thước ô bằng 1/3 kích thước màn hình

enum class Player { None, X, O };

class Board {
public:
    Board(SDL_Renderer* renderer);
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
