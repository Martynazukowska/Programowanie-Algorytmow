#include "game/Pion.hpp"

Pion::Pion(bool czy_jestem_bialy, int X, int Y)
{
  this->name = NAZWAP::Pion;
  this->czy_jest_biale = czy_jestem_bialy;
  this->position_X = X;
  this->position_Y = Y;
  this->czy_gra_trwa = true;
  this->wartosc = 1;
}

Pion::~Pion()
{
  this->name = NAZWAP::nic;
  this->position_X = -1;
  this->position_Y = -1;
  this->czy_gra_trwa = false;
  this->wartosc = -1;
}

bool Pion::czy_moge_sie_ruszyc(int X, int Y)
{
  if(X >= 0 && Y >= 0 && X < 8 && Y < 8 && czy_gra_trwa)  
  {
    int movement_x = X - position_X;
    int movement_y = Y - position_Y;

    if(movement_x == 0 || ((movement_x == -1 && wrog_po_lewej) || (movement_x == 1 && wrog_po_prawej))) 
    {
      if((czy_jest_biale && movement_y < 0) || (!czy_jest_biale && movement_y > 0)) 
      {
        movement_y = abs(movement_y);
        if(movement_y == 2 && movement_x == 0) 
        {
          if(czy_jest_biale && position_Y == 6) 
          {
            return true;
          }

          if(!czy_jest_biale && position_Y == 1) 
          {
            return true;
          }

          return false; //bo to nie jest pierwszy ruch
        }

        if(movement_y == 1) //ruch 1
        {
          return true;
        }
      }
    }
  }

  return false;
}


void Pion::SetDiagonalEnemy(bool Lewy, bool Prawy)
{
  if(czy_jest_biale)
  {
    wrog_po_prawej = Prawy;
    wrog_po_lewej = Lewy;
  }
  else
  {
    wrog_po_prawej = Lewy;
    wrog_po_lewej = Prawy;
  }

}
