#include "texture.h"
#include "Board.h"
// quan li hinh anh
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* boardTexture = NULL;
SDL_Texture* xTexture = NULL;
SDL_Texture* oTexture = NULL;
SDL_Texture* xWinTexture = NULL;
SDL_Texture* oWinTexture = NULL;
SDL_Texture* drawTexture = NULL;
SDL_Texture* menuTexture = NULL;
SDL_Texture* continueTexture = NULL;

// Khởi tạo SDL và IMG
void initSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    srand(time(0)); 
}

// Đóng SDL và IMG
void closeSDL() {
    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(xTexture);
    SDL_DestroyTexture(oTexture);
    SDL_DestroyTexture(xWinTexture);
    SDL_DestroyTexture(oWinTexture);
    SDL_DestroyTexture(drawTexture);
    SDL_DestroyTexture(menuTexture);
    SDL_DestroyTexture(continueTexture); 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
void loadTextures() {
    SDL_Surface* boardSurface = IMG_Load("img/Board.png");
    if (!boardSurface) {
        std::cerr << "Failed to load board.png" << std::endl;
        closeSDL();
        exit(1);
    }
    boardTexture = SDL_CreateTextureFromSurface(renderer, boardSurface);
    SDL_FreeSurface(boardSurface);
    SDL_Surface* xSurface = IMG_Load("img/XX.png");
    if (!xSurface) {
        std::cerr << "Failed to load X.png" << std::endl;
        closeSDL();
        exit(1);
    }
    xTexture = SDL_CreateTextureFromSurface(renderer, xSurface);
    SDL_FreeSurface(xSurface);

    SDL_Surface* oSurface = IMG_Load("img/OO.png");
    if (!oSurface) {
        std::cerr << "Failed to load O.png" << std::endl;
        closeSDL();
        exit(1);
    }
    oTexture = SDL_CreateTextureFromSurface(renderer, oSurface);
    SDL_FreeSurface(oSurface);
    SDL_Surface* xWinSurface = IMG_Load("img/endx1.png");
    if (!xWinSurface) {
        std::cerr << "Failed to load endx1.png" << std::endl;
        closeSDL();
        exit(1);
    }
    xWinTexture = SDL_CreateTextureFromSurface(renderer, xWinSurface);
    SDL_FreeSurface(xWinSurface);

    SDL_Surface* oWinSurface = IMG_Load("img/endo1.png");
    if (!oWinSurface) {
        std::cerr << "Failed to load endo1.png" << std::endl;
        closeSDL();
        exit(1);
    }
    oWinTexture = SDL_CreateTextureFromSurface(renderer, oWinSurface);
    SDL_FreeSurface(oWinSurface);

    SDL_Surface* drawSurface = IMG_Load("img/Draw.png");
    if (!drawSurface) {
        std::cerr << "Failed to load Draw.png" << std::endl;
        closeSDL();
        exit(1);
    }
    drawTexture = SDL_CreateTextureFromSurface(renderer, drawSurface);
    SDL_FreeSurface(drawSurface);

    SDL_Surface* menuSurface = IMG_Load("img/Menu.png");
    if (!menuSurface) {
        std::cerr << "Failed to load Menu.png" << std::endl;
        closeSDL();
        exit(1);
    }
    menuTexture = SDL_CreateTextureFromSurface(renderer, menuSurface);
    SDL_FreeSurface(menuSurface);

    SDL_Surface* continueSurface = IMG_Load("img/continue.png");
    if (!continueSurface) {
        std::cerr << "Failed to load continue.png" << std::endl;
        closeSDL();
        exit(1);
    }
    continueTexture = SDL_CreateTextureFromSurface(renderer, continueSurface);
    SDL_FreeSurface(continueSurface);
}
