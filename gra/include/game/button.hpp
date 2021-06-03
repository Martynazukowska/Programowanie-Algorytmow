#include "Stan.hpp"
#include "pionek.hpp"
#include "dane.hpp"
#include "dane2.hpp"

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
enum class Przyciski
{
    BUTTON_SZI= 0,
    BUTTON_QUIT = 1,
    BUTTON_MAIN_MENU = 2,
    BUTTON_TOTAL = 3
}; 

class Button
{        
        SDL_Point Pozycja;
        Przyciski CurrentPrzycisk;
        int sprawdz = 0;

    public:
        static const int SZEROKOSC_GUZIKA = 340;
        static const int WYSOKOSC_GUZIKA = 340;
        static const int WSZYSTKIE_GUZIKI = 3;
                                                                                                                       
        Button();

        //Od lewy/górny
        void setPosition( int x, int y );
        void setCurrentPrzycisk(Przyciski teraz_przycisk);
        void Przenies( SDL_Event* e , StanGry *gm);

        void render();
};


#endif
