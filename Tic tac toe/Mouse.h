#pragma once
#ifndef MOUSE_H
#define MOUSE_H

#include <SDL.h>
#include "Board.h"

class Mouse {
public:
    static void handleMouseClick(SDL_Event& e, Board& board, char& currentPlayerSymbol);
};

#endif // MOUSE_H
