#ifndef BOARD_H
#define BOARD_H

#include <SDL.h>
// các hằng số
const int BOARD_SIZE = 3;
const int CELL_SIZE = 100; 
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;
// đại diện người chơi
enum class Player { None, X, O };
// chế độ chơi
enum class GameMode { None, Multiplayer, Solo };

extern Player board[BOARD_SIZE][BOARD_SIZE];
extern Player currentPlayer;// trạng thái người chơi
extern GameMode currentMode; // chế độ hiện tại
extern bool running; // trò chơi có đang chạy hay không
extern bool gameOver;// trò chơi đã kết thúc chưa
void resetBoard();// khởi tạo bảng
bool checkWin();// kiểm tra người chiến thắng
bool checkDraw();// kiểm tra hoà
void makeRandomMove();// tạo nước đi ngẫu nhiên
void handleMouseClick(int mouseX, int mouseY);// xử lí nháp chuột
void handleEvent(SDL_Event& event); // xử lí sự kiện

#endif 
