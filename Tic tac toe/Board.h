#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>
#include <string>

const int BOARD_SIZE = 3;

class Board {
public:
    Board(SDL_Renderer* renderer);
    ~Board();

    // Load các hình ảnh X và O
    bool loadMedia();

    // In ra trạng thái hiện tại của bảng
    void print(char board[BOARD_SIZE][BOARD_SIZE]);

private:
    SDL_Renderer* renderer;
    SDL_Texture* boardTexture;
    SDL_Texture* xTexture;
    SDL_Texture* oTexture;
};

#endif // BOARD_H
