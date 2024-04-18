#include "Sound.h"
#include <iostream>
using namespace std;
Mix_Chunk* music = nullptr;

bool initializeSound() {
    if (Mix_Init(MIX_INIT_MP3) == 0) {
        cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << endl;
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "Failed to open audio: " << Mix_GetError() << endl;
        return false;
    }
    return true;
}
bool loadMusic(const char* filename) {
    music = Mix_LoadWAV(filename);
    if (!music) {
        cerr << "Failed to load music: " << Mix_GetError() << endl;
        return false;
    }
    return true;
}
void playMusic(int loops) {
    if (music) {
        Mix_PlayChannel(-1, music, loops);
    }
}

void stopMusic() {
    Mix_HaltChannel(-1);
}

void freeMusic() {
    if (music) {
        Mix_FreeChunk(music);
        music = nullptr;
    }
}

void closeSound() {
    Mix_CloseAudio();
    Mix_Quit();
}
