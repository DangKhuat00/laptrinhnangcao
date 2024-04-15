#include "Board.h"
#include <cstdlib>
#include <ctime>
#include "texture.h"
#include "Window.h"

Player board[BOARD_SIZE][BOARD_SIZE];
bool running = true;
Player currentPlayer = Player::X;
GameMode currentMode = GameMode::None; 

bool gameOver = false; 


void resetBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = Player::None;
        }
    }
}

bool checkWin() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != Player::None && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != Player::None && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] != Player::None && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != Player::None && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == Player::None) {
                return false; 
            }
        }
    }
    return true; 
}

void makeRandomMove() {
    int availableMoves[BOARD_SIZE * BOARD_SIZE][2]; 
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == Player::None) {
                availableMoves[count][0] = i;
                availableMoves[count][1] = j;
                count++;
            }
        }
    }
    if (count > 0) {
        int randomIndex = rand() % count;
        int row = availableMoves[randomIndex][0];
        int col = availableMoves[randomIndex][1];
        board[row][col] = Player::O;
    }
}

void handleMouseClick(int mouseX, int mouseY) {
    if (currentMode == GameMode::None) {
        if (mouseX < SCREEN_WIDTH / 2) {
            currentMode = GameMode::Multiplayer;
        }
        else {
            currentMode = GameMode::Solo;
        }
        return;
    }

    if (gameOver) {
        SDL_Rect continueRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        if (mouseX >= continueRect.x && mouseX <= continueRect.x + continueRect.w &&
            mouseY >= continueRect.y && mouseY <= continueRect.y + continueRect.h) {
            gameOver = false; 
            currentMode = GameMode::None; 
            resetBoard(); 
        }
        return;
    }

    int row = mouseY / CELL_SIZE;
    int col = mouseX / CELL_SIZE;

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == Player::None) {
        board[row][col] = currentPlayer;

        if (checkWin()) {
            if (currentPlayer == Player::X) {
                std::cout << "Player X wins!" << std::endl;
                SDL_RenderCopy(renderer, xWinTexture, NULL, NULL);
                SDL_RenderPresent(renderer);
                SDL_Delay(2000);
                gameOver = true;
            }
            else {
                std::cout << "Player O wins!" << std::endl;
                SDL_RenderCopy(renderer, oWinTexture, NULL, NULL);
                SDL_RenderPresent(renderer);
                SDL_Delay(2000);
                gameOver = true;
            }
        }
        else if (checkDraw()) {
            std::cout << "Draw!" << std::endl;
            SDL_RenderCopy(renderer, drawTexture, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(2000);
            gameOver = true;
        }
        else {
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            if (currentMode == GameMode::Solo && currentPlayer == Player::O) {
                makeRandomMove();
                currentPlayer = Player::X;
                if (checkWin()) {
                    std::cout << "Player O wins!" << std::endl;
                    SDL_RenderCopy(renderer, oWinTexture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(2000);
                    gameOver = true;
                }
                else if (checkDraw()) {
                    std::cout << "Draw!" << std::endl;
                    SDL_RenderCopy(renderer, drawTexture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(2000);
                    gameOver = true;
                }
            }
        }
    }
}

void handleEvent(SDL_Event& event) {
    if (event.type == SDL_QUIT) {
        running = false;
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        handleMouseClick(mouseX, mouseY);
    }
}
