#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include <string>
class Element {

     private:
        SDL_Texture* Tekstura;
        int szerokosc;
        int wysokosc;

    public:
        //inicjalzacja
        Element();

        //destruktor
        ~Element();

        //zaladowanie pliku
        bool loadFromFile( std::string sciezka);

        void free();

        //Renderowanie
        // SDL_Rect a structure that contains the definition of a rectangle, with the origin at the upper left.
        // SDL_Point A structure that defines a two dimensional point.
        // SDL_RendererFlip An enumeration of flags that is used as do not flip
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        //wymiary 
        int getWidth();
        int getHeight();
};

#endif
