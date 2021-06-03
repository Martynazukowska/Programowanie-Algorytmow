#include "game/Kon.hpp"

Kon::Kon(bool czy_jestem_bialy , int X, int Y)
{
  this->name = NAZWAP::Kon;
  this->czy_jest_biale = czy_jestem_bialy;
  this->position_X = X;
  this->position_Y = Y;
  this->czy_gra_trwa = true;
  this->wartosc = 3;
}

Kon::~Kon()
{
  this->name = NAZWAP::nic;
  this->czy_jest_biale = NULL;
  this->position_X = -1;
  this->position_Y = -1;
  this->czy_gra_trwa = NULL;
  this->wartosc = -3;
}


bool Kon::czy_moge_sie_ruszyc(int X, int Y)
{
    //jest na planszy
  if(X >= 0 && Y >= 0 && X < 8 && Y < 8 && czy_jest_biale) 
  {
    int movement_x = abs(X - position_X);
    int movement_y = abs(Y - position_Y);

    //po L sie porusza
    if((movement_x == 1 && movement_y == 2) || (movement_x == 2 && movement_y == 1)) 
    {
      return true;
    }
  }

  return false;
}
