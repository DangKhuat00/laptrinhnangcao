#include "LTexture.h"
#include <SDL_image.h>
#include <iostream>

LTexture::LTexture()
{
    mTexture = nullptr;
    mRenderer = nullptr;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    free();
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path)
{
    // Free existing texture
    free();

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    // Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (mTexture == nullptr)
    {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Get image dimensions
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;

    // Release loaded surface
    SDL_FreeSurface(loadedSurface);

    // Save renderer
    mRenderer = renderer;

    return true;
}

void LTexture::free()
{
    // Free texture if it exists
    if (mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render(int x, int y)
{
    // Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy(mRenderer, mTexture, nullptr, &renderQuad);
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
