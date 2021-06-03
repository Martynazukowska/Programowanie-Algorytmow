#include "game/button.hpp"
Button::Button()
{
    Pozycja.x = 0;
    Pozycja.y = 0;

    CurrentPrzycisk= Przyciski::BUTTON_MAIN_MENU;
}

void Button::setPosition( int x, int y )
{                                                                                                                      
    Pozycja.x = x;
    Pozycja.y = y;
}

void Button::setCurrentPrzycisk(Przyciski pom){
    CurrentPrzycisk = pom;
}

void Button::Przenies( SDL_Event* e , StanGry *gm)
{
    sprawdz = 0;
    // jesli kliknąles
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN ){

        int x, y;
        //pobierz polozenie myszki
        SDL_GetMouseState( &x, &y );

        //w przycisku
        bool inside = true;

        //Na lewo 
        if( x < Pozycja.x ) {
            inside = false;
        }
        //Na prawo
        else if( x > Pozycja.x + SZEROKOSC_GUZIKA ){
            inside = false;
        }
        //Nad
        else if( y < Pozycja.y ){
            inside = false;
        }
        //Pod
        else if( y > Pozycja.y + SZEROKOSC_GUZIKA ) {
            inside = false;
        }

        if( inside ) 
        { 
            sprawdz = 1;
    
            switch( e->type )
            { 
                case SDL_MOUSEMOTION:
                //CurrentPrzycisk = BUTTON_CONTINUE;
                break;

                case SDL_MOUSEBUTTONDOWN:
                    switch(CurrentPrzycisk){
                        case Przyciski::BUTTON_SZI:
                             gm->ustwa_stanGry(TrybGry::GAME_SZI);
                            break;
                        case Przyciski::BUTTON_QUIT:
                             gm->ustwa_stanGry(TrybGry::GAME_QUIT);
                            break;
                        // case ButtonSprite::BUTTON_SPRITE_CONTINUE:
                        //      gm->pause = 0;
                        //      //gm->setGameState(GAME_MODE_CONTINUE);
                        //     break;
                //         case ButtonSprite::BUTTON_SPRITE_SAVE:
                //              gm->pause = 0;
                //              gm->ustwa_stanGry(GameMode::GAME_MODE_SAVE);
                //  //           *gm = GAME_MODE_SAVE;
                //             break;
                //         case ButtonSprite::BUTTON_SPRITE_LOAD:
                //              gm->pause = 0;
                //              gm->ustwa_stanGry(GameMode::GAME_MODE_LOAD);
                //   //          *gm = GAME_MODE_LOAD;
                //             break;
                        case Przyciski::BUTTON_MAIN_MENU:
                             gm->pause = 0;
                             gm->ustwa_stanGry(TrybGry::GAME_MAIN_MENU);
                            break;
                    }
                //mCurrentSprite = BUTTON_SPRITE_SAVE;
                break;
            }
        }
    }
}

void Button::render()
{
    gButtonSpriteSheetTexture.render(Pozycja.x, Pozycja.y, &(gSpriteClips[ (int) CurrentPrzycisk ]) );
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(sprawdz == 1)
    {
        Czarne[(int)NAZWAP::Krol].render(Pozycja.x + SZEROKOSC_GUZIKA/2 - 40 ,Pozycja.y);
    }
}

