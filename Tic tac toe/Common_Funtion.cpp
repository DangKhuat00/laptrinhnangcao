#include"Common_Funtion.h"

bool SDLCommonFunc:: loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load stretching surface
	gStretchedSurface = loadSurface("img/Board.bmp");
	if (gStretchedSurface == NULL)
	{
		printf("Failed to load stretching image!\n");
		success = false;
	}

	gobject1 = loadSurface("img/X.bmp");
	if (gobject1 == NULL)
	{
		success = false;
	}
	else
	{
		SDL_Rect destRect1 = { 100, 100, 0, 0 }; // V? trí hi?n th? cho h?nh ?nh X
		SDL_BlitSurface(gobject1, NULL, gScreenSurface, &destRect1);
	}

	gobject2 = loadSurface("img/O.bmp");
	if (gobject2 == NULL)
	{
		success = false;
	}
	else
	{
		SDL_Rect destRect2 = { 300, 300, 0, 0 }; // V? trí hi?n th? cho h?nh ?nh O
		SDL_BlitSurface(gobject2, NULL, gScreenSurface, &destRect2);
	}

	return success;
}


void SDLCommonFunc:: close()
{
	//Free loaded image
	SDL_FreeSurface(gStretchedSurface);
	gStretchedSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* SDLCommonFunc:: loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}