#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>
//khoi tao doi tuong Board

class Board
{
public:
    Board(int posX, int posY, int width, int height, int rows, int cols);
    void draw(SDL_Renderer* renderer);//ve bang len renderer

private:
    int mPosX;
    int mPosY;
    int mWidth;
    int mHeight;
    int mRows;
    int mCols;
};

#endif // BOARD_H
