#ifndef L_TEXTURE_H
#define L_TEXTURE_H

#include <SDL.h>
#include <string>

class LTexture
{
public:
    // Constructor
    LTexture();

    // Destructor
    ~LTexture();

    // Load texture from file
    bool loadFromFile(SDL_Renderer* renderer, std::string path);

    // Free texture memory
    void free();

    // Render texture at given position
    void render(int x, int y);

    // Get texture width and height
    int getWidth();
    int getHeight();

private:
    // The hardware texture
    SDL_Texture* mTexture;

    // Renderer
    SDL_Renderer* mRenderer;

    // Texture dimensions
    int mWidth;
    int mHeight;
};

#endif  // L_TEXTURE_H
