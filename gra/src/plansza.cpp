#include "game/plansza.hpp"
#include "game/Stan.hpp"

#include <iostream>

void Plansza::Aktualizuj(int x, int y){

    //sprawdz czy jest na planszy
    if((x < 20) || (y < 20) || (x>660) || (y>660) ){
        klikniecie.x = -1;
        klikniecie.y = -1;
        return;
    } else{

        klikniecie.x = (int) (x-20)/80;
        klikniecie.y = (int) (y-20)/80;
    }
}

int Plansza::Kolor(int index)
{

    if((index < 0) || (index > 7))
    {
        std::cout<<"Indice invalido";
        return -1;
    }

    return (index * 80 + 20);

}

void Plansza::Hop_na_plansze(NAZWAP pionek, int a, int x, int y)
{

    if(x < 0 || y < 0){
        return;
    }

    if(a == 0){
        Biale[(int) pionek].render(Kolor(x), Kolor(y));
    } else{
        Czarne[(int) pionek].render(Kolor(x), Kolor(y));
    }
}


void Plansza::wszystko_hop(Zasady* zasady){
    
    //biale
    for(int i = 0 ; i < 16 ; i++){
        Hop_na_plansze(zasady->Biale_pionki[i]->GetName(), 0, zasady->Biale_pionki[i]->GetPositionX(), zasady->Biale_pionki[i]->GetPositionY());
    }

    //czarne
    for(int i = 0 ; i < 16 ; i++){
        Hop_na_plansze(zasady->Czarne_pionki[i]->GetName(), 1, zasady->Czarne_pionki[i]->GetPositionX(),   zasady->Czarne_pionki[i]->GetPositionY());
    }
}

bool Plansza::czy_moge_to_przesunac(Zasady* zasady)
{
    bool przesuniecie = false;
    if(teraz_ja != NULL){
        if(teraz_ja->GetName() != NAZWAP::nic)
        {
            przesuniecie = zasady->czy_moge_przesunac(teraz_ja,klikniecie.x,klikniecie.y);
        }
    }
    return przesuniecie;
}

void Plansza::render_mozliwy_ruch(Zasady *zasady)
{
    if(teraz_ja != NULL){
        if(teraz_ja->GetName() != NAZWAP::nic){
            for(int i = 0 ; i < 8 ; i++)
            {
                for(int j = 0 ; j < 8 ; j++)
                {
                    if(zasady->czy_pozycja_jest_cool(teraz_ja,i,j))
                    {
                      casaVerde.render(Kolor(i),Kolor(j)+2);
                    }
                }
            }
        }

    }
}

void Plansza::render_best_move(Zasady *zasady){

    if(teraz_ja != NULL){
        if(teraz_ja->GetName() != NAZWAP::nic)
        {

            Waga_pionka najlepsza = zasady->GetPionka_BestMove(teraz_ja);

            if(najlepsza.maxx < 0 || najlepsza.maxy < 0)
            {
                return;
            }
            bestMove.render(Kolor(najlepsza.maxx), Kolor(najlepsza.maxy)+2);
        }
    }
}

//strona do rozpoczecia
bool Plansza::kogo_kolej_teraz(StanGry *gm, Zasady *zasady)
{

    bool wybrany = false;
    bool biale = true;

    int x=-1,y=-1;
    SDL_Event event;

    while(wybrany == false)
    {

        while(SDL_PollEvent(&event) != 0)
        {
            if( event.type == SDL_QUIT ) 
            {
                gm->ustwa_stanGry(TrybGry::GAME_QUIT);
            } 
            else if(event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEMOTION)
            {
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        wybrany = true;
                        if(y > 340)
                        {
                            biale = true;
                        } 
                        else
                        {
                            biale = false;
                        } 
                        break;
                    case SDL_MOUSEMOTION: 
                        SDL_GetMouseState(&x,&y);
                        break;
                }
            } 

            


           SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
           SDL_RenderClear( gRenderer );

           //tworzenie tablicy
           gBoard.render(0,0);

           wszystko_hop(zasady);

           //z danych
           if(y < 340)
           {
               wybor.render(20,22);
           } 
           else
           {
               wybor.render(20,342);
           }

            SDL_RenderPresent( gRenderer );
        } 
    }
    return biale;
}

void Plansza::zmiana_na_planszy(StanGry *gm, Zasady* zasady)
{
   
    SDL_Event event;
    bool zrobione = false;

    Pionek *ten = NULL;
    zasady->wyczysc_wszystko();

    int pom = 1;
    //teraz od czarnych
    bool czarne = false;

    int x = -1, y=-1;
    

    while(zrobione == false)
    { 
        while(SDL_PollEvent(&event) != 0)
        {
            if( event.type == SDL_QUIT ) 
            {
                gm->ustwa_stanGry(TrybGry::GAME_QUIT);
            } 
            else if(event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEMOTION)
            {
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_GetMouseState(&x,&y);

                        Aktualizuj(x,y);
                        
                        if(czarne == false)
                        {
                            zasady->mozliwosc_magicznego_ruchu(zasady->Biale_pionki[pom],klikniecie.x,klikniecie.y);
                        } 
                        else
                        {
                            zasady->mozliwosc_magicznego_ruchu(zasady->Czarne_pionki[pom],klikniecie.x,klikniecie.y); 
                        }
                        break;

                    case SDL_MOUSEMOTION: 
                        SDL_GetMouseState(&x,&y);
                        break;
                }
            } 
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        czarne = false;
                        break;
                    case SDLK_DOWN:
                        czarne = true;
                        break;
                    case SDLK_LEFT:
                        if(pom >0)
                        {
                            pom--;
                        }
                        else
                        {
                            pom = 15;
                        }
                        break;
                    case SDLK_RIGHT:
                        if(pom <15)
                        {
                            pom++;
                        }
                        else
                        {
                            pom = 0;
                        }
                        break;
                    case SDLK_d:
                        zrobione = true;
                        break;

                }
            }

           SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
           SDL_RenderClear( gRenderer );

           //na plansze
           gBoard.render(0,0);

           if(czarne == false){
               Biale[(int)zasady->Biale_pionki[pom]->GetName()].render(x,y);
           } else{
               Czarne[(int)zasady->Czarne_pionki[pom]->GetName()].render(x,y);
           }

            wszystko_hop(zasady);

           SDL_RenderPresent( gRenderer );
        } 
    }

    return;
}
