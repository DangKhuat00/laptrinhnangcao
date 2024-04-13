#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>

const int BOARD_SIZE = 3;
const int CELL_SIZE = 200; 
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
// Định nghĩa enum cho người chơi và chế độ chơi
enum class Player { None, X, O };
enum class GameMode { None, Multiplayer, Solo };

// Biến toàn cục để theo dõi trạng thái của trò chơi
extern Player board[BOARD_SIZE][BOARD_SIZE];
extern Player currentPlayer;
extern GameMode currentMode;
extern bool running;
extern bool gameOver;
void resetBoard();
bool checkWin();
bool checkDraw();
void makeRandomMove();
void handleMouseClick(int mouseX, int mouseY);
void handleEvent(SDL_Event& event);

#endif // GAME_H
