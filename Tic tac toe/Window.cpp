#include "Window.h"
#include "texture.h"
#include "Board.h"

void drawBoard() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    SDL_Rect destRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderCopy(renderer, boardTexture, NULL, &destRect);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            SDL_Rect cellRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            if (board[i][j] == Player::X) {
                SDL_RenderCopy(renderer, xTexture, NULL, &cellRect);
            }
            else if (board[i][j] == Player::O) {
                SDL_RenderCopy(renderer, oTexture, NULL, &cellRect);
            }
        }
    }

    SDL_RenderPresent(renderer);
}
 
void drawMenu() {
    SDL_Rect destRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderCopy(renderer, menuTexture, NULL, &destRect);
    SDL_RenderPresent(renderer);
}

void drawContinueScreen() {
    SDL_Rect destRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderCopy(renderer, continueTexture, NULL, &destRect);
    SDL_RenderPresent(renderer);
}
