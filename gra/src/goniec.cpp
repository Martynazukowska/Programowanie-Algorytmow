#include "game/goniec.hpp"


Goniec::Goniec(bool czy_jestem_bialy, int X, int Y)
{
  this->name = NAZWAP::Goniec;
  this->czy_jest_biale = czy_jestem_bialy;
  this->position_X = X;
  this->position_Y = Y;
  this->czy_gra_trwa = true;
  this->wartosc = 3;
}

Goniec::~Goniec()
{

  this->name = NAZWAP::nic;
  this->czy_jest_biale = NULL;
  this->position_X = -1;
  this->position_Y = -1;
  this->czy_gra_trwa = NULL;
  this->wartosc = -1;
}


bool Goniec::czy_moge_sie_ruszyc(int X, int Y)
{
  if(X >= 0 && Y >= 0 && X < 8 && Y < 8 && czy_jest_biale) //musi byc na planszy i musi zyc
  {
      //NIE MOGE BYC UJEMNA
    int movement_x = abs(X - position_X); 
    int movement_y = abs(Y - position_Y);

    if(movement_x == movement_y && movement_x > 0) //ruch po  przekontnej
    {
      return true;
    }
  }

  return false;
}
