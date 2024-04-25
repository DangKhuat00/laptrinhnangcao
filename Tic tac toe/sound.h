#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>

bool initializeSound(); 
bool loadMusic(const char* filename); 
void playMusic(int loops); 
void stopMusic(); 
void freeMusic(); 
void closeSound(); 

#endif 
