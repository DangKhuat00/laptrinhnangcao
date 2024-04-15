#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

extern SDL_Window* window;// cua so
extern SDL_Renderer* renderer; // hien thi hinh anh len window

// khai báo các texture
extern SDL_Texture* boardTexture;
extern SDL_Texture* xTexture;
extern SDL_Texture* oTexture;
extern SDL_Texture* xWinTexture;
extern SDL_Texture* oWinTexture;
extern SDL_Texture* drawTexture;
extern SDL_Texture* menuTexture;
extern SDL_Texture* continueTexture;
void initSDL(); // khởi tạo sdl
void closeSDL(); // đóng và dọn dẹp tài nguyên sdl
void loadTextures(); // tai texture

#endif 
