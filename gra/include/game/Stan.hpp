#ifndef STAN_HPP
#define STAN_HPP

#include "element.hpp"                                                   
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "dane.hpp"

enum class TrybGry {
    GAME_SZI = 0,
    GAME_QUIT = 1,
    GAME_MAIN_MENU = 2,
    GAME_TOTAL = 3

};

class StanGry
{
        TrybGry gameState;
        void renderMainMenu();
        void renderSZI();
    
    public: 
        StanGry();
        int pause = 0;

        TrybGry getTrybGry();
        void ustwa_stanGry(TrybGry gameMode);
        void start(TrybGry gameMode);
};

#endif
