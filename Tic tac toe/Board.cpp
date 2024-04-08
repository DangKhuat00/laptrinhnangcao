#include "Board.h"
#include<algorithm>
Board::Board(int posX, int posY, int width, int height, int rows, int cols)
    : mPosX(posX), mPosY(posY), mWidth(width), mHeight(height), mRows(rows), mCols(cols)
{}

void Board::draw(SDL_Renderer* renderer)
{
    // Calculate square size
    int squareSize = std::min(mWidth / mCols, mHeight / mRows);

    // Calculate padding
    int paddingX = (mWidth - mCols * squareSize) / 2;
    int paddingY = (mHeight - mRows * squareSize) / 2;

    // Draw Tic Tac Toe board
    for (int row = 0; row < mRows; ++row)
    {
        for (int col = 0; col < mCols; ++col)
        {
            int posX = mPosX + paddingX + col * squareSize;
            int posY = mPosY + paddingY + row * squareSize;

            // Draw square
            SDL_Rect squareRect = { posX, posY, squareSize, squareSize };
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
            SDL_RenderDrawRect(renderer, &squareRect);
        }
    }
}

void Board::handleMouseClick(int mouseX, int mouseY, char currentPlayerSymbol) {
    // Your logic to handle mouse click goes here
}
