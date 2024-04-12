#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

// Khai báo các biến toàn cục cho các texture
extern SDL_Texture* boardTexture;
extern SDL_Texture* xTexture;
extern SDL_Texture* oTexture;
extern SDL_Texture* xWinTexture;
extern SDL_Texture* oWinTexture;
extern SDL_Texture* drawTexture;
extern SDL_Texture* menuTexture;
extern SDL_Texture* continueTexture;
void initSDL();
void closeSDL();
void loadTextures();

#endif // TEXTURE_H
