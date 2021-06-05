#include "game/grafika.hpp"
#include "game/pionek.hpp"
#include <cstdio>
#include "game/Stan.hpp"
#include "game/Pion.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>

//Mouse button sprites
SDL_Rect gSpriteClips[(int) Przyciski::BUTTON_TOTAL ];
Element gCheckTexture;
Element gButtonSpriteSheetTexture;
//Buttons objects
Button gButtons[ Button::WSZYSTKIE ];
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
//Scene textures
Element gBoard;
Element casaVerde;
Element Biale[7];
Element Czarne[7];
Element wybrany;
Element wybor;
Element pieceSelected;
Element bestMove;
Element endGame[3];

bool Graphics::loadMedia() {
    bool success = true;

    if( !wybor.loadFromFile( "../data/Selection.png" ) ) {
        std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !gBoard.loadFromFile( "../data/Chess_Stone.png" ) ) {
        std::cout<< "Failed to load texture!\n";
        success = false;
    }

    if( !Biale[(int)NAZWAP::Pion].loadFromFile( "../data/PawnW.png") ) {
        std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Biale[(int)NAZWAP::Kon].loadFromFile( "../data/KnightW.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Biale[(int)NAZWAP::Goniec].loadFromFile( "../data/BishopW.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Biale[(int)NAZWAP::Wieza].loadFromFile( "../data/RookW.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Biale[(int)NAZWAP::Krolowa].loadFromFile( "../data/QueenW.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Biale[(int)NAZWAP::Krol].loadFromFile( "../data/KingW.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }


    if( !Czarne[(int)NAZWAP::Pion].loadFromFile( "../data/PawnB.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Czarne[(int)NAZWAP::Kon].loadFromFile( "../data/KnightB.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Czarne[(int)NAZWAP::Goniec].loadFromFile( "../data/BishopB.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Czarne[(int)NAZWAP::Wieza].loadFromFile( "../data/RookB.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Czarne[(int)NAZWAP::Krolowa].loadFromFile( "../data/QueenB.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }
    if( !Czarne[(int)NAZWAP::Krol].loadFromFile( "../data/KingB.png") ) {
         std::cout<<"Failed to load texture!\n";
        success = false;
    }

    
        //Do wygladu menu
    if( !gButtonSpriteSheetTexture.loadFromFile( "../data/menus.png") ) {
         std::cout<<"Failed to load button  texture!\n";
        success = false;
    }
    else
    {
        //pola
        for( int i = 0; i < (int) Przyciski::BUTTON_TOTAL; ++i )
        {
            gSpriteClips[ i ].x = 0;
            gSpriteClips[ i ].y = i * 340;
            gSpriteClips[ i ].w = Button::SZEROKOSC_GUZIKA;
            gSpriteClips[ i ].h = Button::WYSOKOSC_GUZIKA;
        }

        gButtons[ 0 ].setPosition( 0, 0 );
        gButtons[ 1 ].setPosition( SCREEN_WIDTH - Button::SZEROKOSC_GUZIKA, 0 );
        gButtons[ 2 ].setPosition( 0, SCREEN_HEIGHT - Button::WYSOKOSC_GUZIKA );
        gButtons[ 3 ].setPosition( SCREEN_WIDTH - Button::SZEROKOSC_GUZIKA, SCREEN_HEIGHT - Button::WYSOKOSC_GUZIKA );
        gButtons[ 4 ].setPosition( 0, 0 );
        gButtons[ 5 ].setPosition( SCREEN_WIDTH - Button::SZEROKOSC_GUZIKA, 0 );                                                                                                                  
        gButtons[ 6 ].setPosition( 0, SCREEN_HEIGHT - Button::WYSOKOSC_GUZIKA );
        gButtons[ 7 ].setPosition( SCREEN_WIDTH - Button::WYSOKOSC_GUZIKA, SCREEN_HEIGHT - Button::WYSOKOSC_GUZIKA );

    }
    return success;
}

bool Graphics::init(){

    bool success = true;
    std::cout<<"bum";
    //Inicializa o  SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        std::cout<<"problem z inicjalizacja";
        SDL_GetError();
        success = false;
    }
    else 
    {
        //Set a hint with normal priority.
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            std::cout<<"Uwaga tekst";
        }

        //okno 
        gWindow = SDL_CreateWindow( "Szachy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL ){
            std::cout<<"Problem ze stworzeniem okna\n"; 
            SDL_GetError();
            success = false;
        }
        else
        {
            //render
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                std::cout<<"Problem z renderowaniem\n";
                 SDL_GetError();
                success = false;
            }
            else
            {
                //kolor
                SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );

                // png
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    std::cout<<"problem z IMG\n";
                    IMG_GetError() ;
                    success = false;                                                                                                                                                          
                }
            }
        }
    }
    return success;
}

void Graphics::close() {

    gBoard.free();

    for(int i = 1 ; i < 7 ; i++){
        Biale[i].free();
    }

    for(int i = 1 ; i < 7 ; i++){
        Czarne[i].free();
    }

    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit(); //trzeba dodac
    SDL_Quit();
}
