#ifndef PIONEK_HPP
#define PIONEK_HPP

#include <iostream>
#include <string>

enum class NAZWAP {nic , Pion , Kon , Goniec , Wieza , Krolowa , Krol};

using namespace std;

class Pionek
{
  protected:
    NAZWAP name; 
    int position_X;  
    int position_Y;  
    bool czy_gra_trwa; 
    bool czy_jest_biale;
    int wartosc;

  public:
    Pionek();
    int  Getwartosc();
    bool GetColor();  
    bool Getczy_gra_trwa();    
    NAZWAP GetName();  
    int GetPositionX();    
    int GetPositionY();   

    virtual bool czy_moge_sie_ruszyc(int pom, int pom2); 
    virtual void Kierunek(bool pom, bool pom2); 

    void SetPosition(int pom, int pom2); 
   
    void odrodzenie(); 
    void umzyj();       
};

#endif
