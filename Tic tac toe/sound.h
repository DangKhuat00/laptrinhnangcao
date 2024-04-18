#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>

bool initializeSound(); // Khởi tạo âm thanh
bool loadMusic(const char* filename); // Tải nhạc
void playMusic(int loops); // Phát nhạc
void stopMusic(); // Dừng phát nhạc
void freeMusic(); // Giải phóng nhạc
void closeSound(); // Đóng âm thanh

#endif 
