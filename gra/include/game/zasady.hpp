#ifndef ZASADY_HPP
#define ZASADY_HPP

#include "pionek.hpp"
#include "Stan.hpp"


enum class klasa{nic,ty,przeciwnik};
enum class Wynik{Biale,Czarne,Remis,Brak};

struct Waga_pionka
{
  int maxx = -1;
  int maxy = -1;
  int Waga = -20;
};

class Zasady
{
    Pionek * niewiadomo = new Pionek();
    bool czy_kolej_bialych; 

    void SetKierunek(bool pom, Pionek * jakis, int a, int b);
    void zbij(int x, int y);    
    void zamiana_pionka(Pionek * cos);

  public:
    Zasady();
    //njlepszy ruk kazdego elementu
    Waga_pionka waga_czarnych[16];
    Waga_pionka waga_bialych[16];
    //pionki
    Pionek * Biale_pionki[16];
    Pionek * Czarne_pionki[16];

    klasa czy_cos_jest_na_drodze(Pionek *jakis, int x, int y);
    klasa cos_na_tym_miejscu(Pionek *jakis, int x, int y);

    bool sprawdz_czy_jest_szach(bool kolor_krola, int x, int y);
    bool czy_moge_przesunac(Pionek * cos, int x, int y);  

    bool czy_jest_szach_mat(bool kolorkrola);
    Wynik kto_wygral();

    bool czy_pozycja_jest_cool(Pionek * cos, int x, int y);  
    Pionek * GetPionek(int x, int y); 
    bool mozliwosc_magicznego_ruchu(Pionek * cos, int x, int y); 

    Waga_pionka GetPionka_BestMove(Pionek * jakis); 
    void PlayBestMove(bool kolor);  

    void UpdateBestMoves(); 
    void SetKolejke_pionka(bool czyja_kolej);  
    bool Getkolejke_pionka();

    

    void wyczysc_wszystko();
};

#endif
