#ifndef GRAFIKA_HPP
#define GRAFIKA_HPP

#include "element.hpp"
#include "button.hpp"
#include "dane.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>


#include <string> 

// SDL_Rect gSpriteClips[(int) Przyciski::BUTTON_TOTAL ];
//  Element gCheckTexture;
//  Element gButtonSpriteSheetTexture;
//  Button gButtons[ Button::WSZYSTKIE_GUZIKI ];
//  SDL_Window* gWindow;
//  SDL_Renderer* gRenderer;

//  Element gBoard;
//  Element Biale[7];
//  Element Czarne[7];
//  Element wybrany;
//  Element wbor;


class Graphics{
    public: 

        bool init();
        bool loadMedia();
        void close(); 

        const int SCREEN_WIDTH = 680;
        const int SCREEN_HEIGHT = 680;
}; 
#endif 

