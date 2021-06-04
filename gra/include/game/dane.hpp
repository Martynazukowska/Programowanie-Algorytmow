#ifndef DANE_HPP
#define DANE_HPP

#include "element.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>


#include <string> 

// extern SDL_Rect gSpriteClips[(int) Przyciski::BUTTON_TOTAL ];
extern Element gCheckTexture;
extern Element gButtonSpriteSheetTexture;
//Buttons objects
// extern Button gButtons[ Button::WSZYSTKIE_GUZIKI ];
//The window we'll be rendering to
extern SDL_Window* gWindow;
//The window renderer
extern SDL_Renderer* gRenderer;
//Scene textures
extern Element gBoard;
extern Element Biale[7];
extern Element Czarne[7];
extern Element wybrany;
extern Element wybor;
extern Element casaVerde;
extern Element pieceSelected;
extern Element bestMove;
extern Element endGame[3];
#endif 
