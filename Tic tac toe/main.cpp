#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Board.h"
#include "LTexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 575;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia(SDL_Renderer* renderer, LTexture& boardTexture);

//Frees media and shuts down SDL
void close(SDL_Window* window, SDL_Renderer* renderer);

int main(int argc, char* args[])
{
    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;

    //The window renderer
    SDL_Renderer* gRenderer = nullptr;

    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                }
                else
                {
                    //Create texture
                    LTexture gBoardTexture;

                    //Load media
                    if (!loadMedia(gRenderer, gBoardTexture))
                    {
                        printf("Failed to load media!\n");
                    }
                    else
                    {
                        //Main loop flag
                        bool quit = false;

                        //Event handler
                        SDL_Event e;

                        //While application is running
                        while (!quit)
                        {
                            //Handle events on queue
                            while (SDL_PollEvent(&e) != 0)
                            {
                                //User requests quit
                                if (e.type == SDL_QUIT)
                                {
                                    quit = true;
                                }
                            }

                            //Clear screen
                            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                            SDL_RenderClear(gRenderer);

                            //Render board texture to screen
                            gBoardTexture.render(0, 0);

                            //Update screen
                            SDL_RenderPresent(gRenderer);
                        }
                    }
                }
            }
        }
    }

    //Free resources and close SDL
    close(gWindow, gRenderer);

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

bool loadMedia(SDL_Renderer* renderer, LTexture& boardTexture)
{
    //Loading success flag
    bool success = true;

    //Load board texture
    if (!boardTexture.loadFromFile(renderer, "img/Board1.png"))
    {
        printf("Failed to load board texture image!\n");
        success = false;
    }

    return success;
}

void close(SDL_Window* window, SDL_Renderer* renderer)
{
    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
