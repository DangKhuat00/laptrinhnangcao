#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Board.h"
#include "Window.h"
#include "texture.h"
#include "sound.h"

int main(int argc, char* args[]) {
    initSDL();
    if (!initializeSound()) {
        return -1; 
    }
    if (!loadMusic("music/Music.mp3")) {
        return -1; 
    }
    playMusic(-1);
    loadTextures();
    while (currentMode == GameMode::None) {
        drawMenu();
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            handleEvent(event);
        }
    }
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
    stopMusic();
    freeMusic();
    closeSound();
    closeSDL();
    return 0;
}
