#include "game/pionek.hpp"

Pionek::Pionek()
{
    NAZWAP name = NAZWAP::nic; 
    int position_X = -1;  
    int position_Y = -1;  
    bool czy_gra_trwa = false; 
    bool czy_jest_biale = false;
    int wartosc= -1;
}

int Pionek::Getwartosc()
{
    return wartosc;
}

bool Pionek::GetColor()
{
  return czy_jest_biale;
}

bool Pionek::Getczy_gra_trwa()
{
  return czy_gra_trwa;
}

NAZWAP Pionek::GetName()
{
  return name;
}

int Pionek::GetPositionX()
{
  return position_X;
}

int Pionek::GetPositionY()
{
  return position_Y;
}


bool Pionek::czy_moge_sie_ruszyc(int pom, int pom2)
{
  return false;
}

void Pionek::Kierunek(bool pom, bool pom2)
{
    //puste
}


void Pionek::SetPosition(int pom, int pom2)
{
  if(czy_gra_trwa)
  {
    this->position_X = position_X;
    this->position_Y = position_Y;
  }
}

void Pionek::umzyj()
{
  this->position_X = -1;
  this->position_Y = -1;
  czy_gra_trwa = false;

}

void Pionek::odrodzenie()
{
  czy_gra_trwa = true;
}

