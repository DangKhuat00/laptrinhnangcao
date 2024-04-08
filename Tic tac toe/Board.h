#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>

class Board {
public:
    Board(int posX, int posY, int width, int height, int rows, int cols);
    void draw(SDL_Renderer* renderer);
    void handleMouseClick(int mouseX, int mouseY, char currentPlayerSymbol);

private:
    int mPosX;
    int mPosY;
    int mWidth;
    int mHeight;
    int mRows;
    int mCols;
};

#endif // BOARD_H
