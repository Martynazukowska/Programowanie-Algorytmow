#include "game/wieza.hpp"

Wieza::Wieza(bool czy_jestem_bialy, int X, int Y)
{
  this->name = NAZWAP::Wieza;
  this->czy_jest_biale = czy_jestem_bialy;
  this->position_X = X;
  this->position_Y = Y;
  this->czy_gra_trwa = true;
  this->wartosc = 5;
}

Wieza::~Wieza()
{\
  this->name = NAZWAP::nic;
  this->czy_jest_biale = NULL;
  this->position_X = -1;
  this->position_Y = -1;
  this->czy_gra_trwa = NULL;
  this->wartosc = -1;

}


bool Wieza::czy_moge_sie_ruszyc(int X, int Y)
{
    //czy jest na planszy
  if(X >= 0 && Y >= 0 && X < 8 && Y < 8 && czy_gra_trwa)
  {
    int movement_x = abs(X - position_X);
    int movement_y = abs(Y - position_Y);
     
     //w pionie
    if((movement_x == 0 || movement_y == 0) && movement_x != movement_y)
    {
      return true;
    }
  }

  return false;
}