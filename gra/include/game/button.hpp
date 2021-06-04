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
    BUTTON_SZI = 0,
    BUTTON_QUIT = 3,
    //PLANSZA PODZIELONA NA 4 na miejscu 0 i 3 przyciski 
    //dodatkowe dane 
    BUTTON_MAIN_MENU = 7,
    BUTTON_TOTAL = 8
}; 

class Button
{        
        SDL_Point Pozycja;
        Przyciski CurrentPrzycisk;
        int sprawdz = 0;

    public:
    //statuc potrzebne do SDL
        static const int SZEROKOSC_GUZIKA = 340;
        static const int WYSOKOSC_GUZIKA = 340;
        static const int WSZYSTKIE= 8;
                                                                                                                       
        Button();

        //Od lewy/górny
        void setPosition( int x, int y );
        void setCurrentPrzycisk(Przyciski teraz_przycisk);
        void Przenies( SDL_Event* e , StanGry *gm);

        void render();
};


#endif
