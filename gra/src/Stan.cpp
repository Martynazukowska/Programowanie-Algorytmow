#include "game/Stan.hpp"
#include "game/zasady.hpp"

#include <cstdio>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include "game/pionek.hpp"
#include "game/plansza.hpp"
#include "game/dane2.hpp"

StanGry::StanGry(){
    gameState = TrybGry::GAME_MAIN_MENU;
}

TrybGry StanGry::getTrybGry(){
    return gameState;
}


void StanGry::ustwa_stanGry(TrybGry gameMode){
    gameState = gameMode;
}

void StanGry::renderMainMenu(){

    bool quit = false;

    for (int i = 0 ; i < Button::WSZYSTKIE_GUZIKI/2 ; i++)
    {
        gButtons[i].setCurrentPrzycisk((Przyciski) i);
    }

    SDL_Event event;

    while(gameState == TrybGry::GAME_MAIN_MENU)
    {

            while( SDL_PollEvent( &event ) != 0 )
            {
                if( event.type == SDL_QUIT )
                {
                    gameState = TrybGry::GAME_QUIT;
                }
                for( int i = 0; i < Button::WSZYSTKIE_GUZIKI/2; ++i ) {
                    gButtons[ i ].Przenies( &event, this);
                }
            }

            //oczysc
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

    
            for( int i = 0; i < Button::WSZYSTKIE_GUZIKI/2; ++i )
            {
                gButtons[ i ].render();
            }

            SDL_RenderPresent( gRenderer );

    }
}

void StanGry::renderSZI(){

    bool quit = false;
    int x = -1, y = -1;

    bool czy_jestem_bialy = true; //bialy
    bool kolejka_komputera = false; 

    SDL_Event event;
    
    Zasady *zasady = new Zasady();
    Plansza *plansza = new Plansza();
    Wynik wynik = Wynik::Brak;


    czy_jestem_bialy = plansza->kogo_kolej_teraz(this,zasady); 
    zasady->SetKolejke_pionka(czy_jestem_bialy);


    while(gameState == TrybGry::GAME_SZI)
    {
        while( SDL_PollEvent( &event ) != 0 ) 
        {
            if( event.type == SDL_QUIT )
            {
                gameState = TrybGry::GAME_QUIT;
            } 
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN: 
                        if(kolejka_komputera == false)
                        {
                            x = -1;
                            y = -1;
                            SDL_GetMouseState(&x,&y); 
                            plansza->Aktualizuj((int)x,(int)y); 

                            if(plansza->czy_moge_to_przesunac(zasady))
                            {
                                plansza->teraz_ja = NULL;
                            }
                            else
                            {
                               
                                plansza->teraz_ja = zasady->GetPionek(plansza->klikniecie.x,plansza->klikniecie.y);
                            }
                            break;
                            kolejka_komputera = true;
                        }
                }
            }

        }

    
       SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
       SDL_RenderClear( gRenderer );

       //plansza
       gBoard.render(0,0);
       
       wynik = zasady->kto_wygral();
       if(wynik == Wynik::Brak)
       {
           if(kolejka_komputera = true)
           {
               zasady->PlayBestMove(!czy_jestem_bialy);
               kolejka_komputera = false;
           }

           if((plansza->teraz_ja != NULL) )
           {
               if(plansza->teraz_ja->GetName() != NAZWAP::nic && (plansza->teraz_ja->GetColor() == zasady->Getkolejke_pionka() ))
               {
                   //z danych
                   pieceSelected.render(plansza->Kolor(plansza->klikniecie.x),plansza->Kolor(plansza->klikniecie.y)+2);
               }
        
               if(plansza->teraz_ja->GetColor() == zasady->Getkolejke_pionka())
               {
                   plansza->render_mozliwy_ruch(zasady);
               }
               if(plansza->teraz_ja->GetColor() == zasady->Getkolejke_pionka())
               {
                   plansza->render_best_move(zasady);
               }
            }
           plansza->wszystko_hop(zasady);

       } 
       else
       {
           endGame[(int)wynik].render(0,0);
       }

       SDL_RenderPresent( gRenderer );
    }
    delete zasady;
    delete plansza;
}

void StanGry::start(TrybGry gameMode){

    gameState = gameMode;

    while(gameState != TrybGry::GAME_QUIT){

        switch(gameState){
            case TrybGry::GAME_MAIN_MENU:
                renderMainMenu();
                break;
            case TrybGry::GAME_SZI:
                renderSZI();
                break;
        }
    }
}
