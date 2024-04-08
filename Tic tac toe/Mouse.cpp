#include "mouse.h"

void Mouse::handleMouseClick(SDL_Event& e, Board& board, char& currentPlayerSymbol) {
    // Handle mouse click event
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Call board's handleMouseClick function
        board.handleMouseClick(mouseX, mouseY, currentPlayerSymbol);
    }
}
