#include "Board.h"
#include <algorithm>

Board::Board(int posX, int posY, int width, int height, int rows, int cols)
    : mPosX(posX), mPosY(posY), mWidth(width), mHeight(height), mRows(rows), mCols(cols)
{}

void Board::draw(SDL_Renderer* renderer)
{
    // Tính toán kích thước của mỗi ô vuông
    int squareSize = std::min(mWidth / mCols, mHeight / mRows);

    // Tính toán khoảng cách giữa các ô vuông
    int paddingX = (mWidth - mCols * squareSize) / 2;
    int paddingY = (mHeight - mRows * squareSize) / 2;

    // Vẽ bảng Tic Tac Toe
    for (int row = 0; row < mRows; ++row)
    {
        for (int col = 0; col < mCols; ++col)
        {
            // Tính toán vị trí của ô vuông
            int posX = mPosX + paddingX + col * squareSize;
            int posY = mPosY + paddingY + row * squareSize;

            // Vẽ ô vuông
            SDL_Rect squareRect = { posX, posY, squareSize, squareSize };
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Đặt màu đen cho ô vuông
            SDL_RenderDrawRect(renderer, &squareRect);
        }
    }
}
