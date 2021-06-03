#include "game/element.hpp"
#include "game/dane.hpp"

#include <iostream>

// SDL_Renderer* gRenderer = NULL;

Element::Element()
{
    Tekstura = NULL;
    szerokosc = 0;
    wysokosc = 0;
}

Element::~Element()
{
    free();
}


bool Element::loadFromFile( std::string sciezka )
{
    //pozbywamy sie tego co mielismy wczesniej
    free();

    SDL_Texture* newTexture = NULL;

    //zaladowanie obrazu
    SDL_Surface* loadedSurface = IMG_Load( sciezka.c_str() );
    if( loadedSurface == NULL )
    {
        std::cout<<"Problem z załadowaniem zdjecia \n"<<sciezka.c_str();
    }
    else
    {
        // przezroczystosc
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ));

        //SDL_CreateTextureFromSurface Create a texture from an existing surface.
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

        if( newTexture == NULL )
        {
            std::cout<<"Blad ze stworzeniem elementu \n"<<sciezka.c_str();
            SDL_GetError();
        }

        else
        {
            //przypisywanie wartosci
            szerokosc = loadedSurface->w;
            wysokosc = loadedSurface->h;
        }

        //zwalnianie pamieci
        SDL_FreeSurface( loadedSurface );
    }

    Tekstura = newTexture;
    return Tekstura!= NULL;
}

void Element::free()
{
    if( Tekstura != NULL )
    {
        SDL_DestroyTexture( Tekstura );
        Tekstura = NULL;
        szerokosc = 0;
        wysokosc = 0;
    }
}

void Element::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //czesc renderowania 
    SDL_Rect renderQuad = { x, y, szerokosc, wysokosc };

    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //renderuj na ekranie
    SDL_RenderCopyEx( gRenderer, Tekstura , clip, &renderQuad, angle, center, flip );
}

int Element::getWidth()
{
    return szerokosc;
}

int Element::getHeight()
{
    return wysokosc;
}

