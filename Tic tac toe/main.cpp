#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Board.h"
#include "Window.h"
#include "texture.h"
#include <iostream>

int main(int argc, char* args[]) {
    initSDL();
    // tải âm thanh
    if (Mix_Init(MIX_INIT_MP3) == 0) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        return -1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to open audio: " << Mix_GetError() << std::endl;
        return -1;
    }
    Mix_Chunk* music = Mix_LoadWAV("music/Music.mp3");
    if (!music) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        return -1;
    }

    // Phát nhạc và lặp lại vô hạn
    Mix_PlayChannel(-1, music, -1);
    loadTextures();
    while (currentMode == GameMode::None) {
        drawMenu();
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            handleEvent(event);
        }
    }
    // Khởi động trò chơi
    resetBoard();
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            handleEvent(event);
        }
        if (gameOver) {
            drawContinueScreen();
        }
        else {
            drawBoard();
        }
    }
    Mix_HaltChannel(-1);
    Mix_FreeChunk(music);
    Mix_CloseAudio();
    closeSDL();
    return 0;
}
