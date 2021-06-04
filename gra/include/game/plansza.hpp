#ifndef PLANSZA_HPP
#define PLANSZA_HPP


#include "zasady.hpp"
#include "pionek.hpp"
#include "dane.hpp"
#include "dane2.hpp"


class Plansza{
    public:
    SDL_Rect plansza[8][8]; 
    SDL_Point klikniecie = {-1,-1}; 

    Pionek *teraz_ja = NULL; 


	//aktualizuj pozycje
    void Aktualizuj(int x, int y);
	//zwraca kolor pionka 0 bialy 1 czarny
    int Kolor(int index);
	//na planszy
    void Hop_na_plansze(NAZWAP pionek, int a, int ix, int iy); 
    void wszystko_hop(Zasady* jakies);
    bool czy_moge_to_przesunac(Zasady* zasady); 

    void render_mozliwy_ruch(Zasady *zasady); 
    void render_best_move(Zasady *zasady); 

    bool kogo_kolej_teraz(StanGry *gm, Zasady* states);
    void zmiana_na_planszy(StanGry *gm, Zasady* states);

};

#endif