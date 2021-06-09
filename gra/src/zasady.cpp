#include "game/pionek.hpp"
#include "game/Pion.hpp"
#include "game/krol.hpp"
#include "game/goniec.hpp"
#include "game/wieza.hpp"
#include "game/krol.hpp"
#include "game/krolowa.hpp"
#include "game/Kon.hpp"


#include "game/zasady.hpp"
#include "game/Stan.hpp"

#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;


Zasady::Zasady()
{

//wszysto inicjujemy 
  for(int i=0;i<=7;i++)
  {
    Biale_pionki[i] = new Pion(true, i, 6);
    Czarne_pionki[i] = new Pion(false, i, 1);
  }

  Biale_pionki[8]  = new Wieza(true, 0, 7);
  Biale_pionki[9]  = new Kon(true, 1, 7);
  Biale_pionki[10] = new Goniec(true, 2, 7);
  Biale_pionki[11] = new Krolowa(true, 3, 7);
  Biale_pionki[12] = new Krol(true, 4, 7);
  Biale_pionki[13] = new Goniec(true, 5, 7);
  Biale_pionki[14] = new Kon(true, 6, 7);
  Biale_pionki[15] = new Wieza(true, 7, 7);

  Czarne_pionki[8]  = new Wieza(false, 0, 0);
  Czarne_pionki[9]  = new Kon(false, 1, 0);
  Czarne_pionki[10] = new Goniec(false, 2, 0);
  Czarne_pionki[11] = new Krolowa(false, 3, 0);
  Czarne_pionki[12] = new Krol(false, 4, 0);
  Czarne_pionki[13] = new Goniec(false, 5, 0);
  Czarne_pionki[14] = new Kon(false, 6, 0);
  Czarne_pionki[15] = new Wieza(false, 7, 0);

  czy_kolej_bialych = true;
}








void Zasady::SetKierunek(bool pom, Pionek * jakis, int x, int y)
{
  int i, vertical, horizontal;

  bool left = false, right = false;

  if(jakis->GetName() == NAZWAP::Pion)
  {
    if(pom)
    {
      jakis->GetColor() ? (vertical = (jakis->GetPositionY() - 1)) : (vertical = (jakis->GetPositionY() + 1));
      horizontal = (jakis->GetPositionX() + 1);

      for(i = 0; i < 2; i++)
      {
        if(cos_na_tym_miejscu(jakis, horizontal, vertical) == klasa::przeciwnik)
          (i == 0) ? (jakis->GetColor() ? right = true : left = true) : (jakis->GetColor() ? left = true : right = true);

        horizontal = (jakis->GetPositionX() -1);
      }

      if((abs(x - jakis->GetPositionX()) == 1) && (abs(y - jakis->GetPositionY()) == 1) && (x != -1) && (y != -1))
      {
        jakis->GetColor() ? ((x - jakis->GetPositionX()) == 1 ? right = true : left = true) : ((x - jakis->GetPositionX()) == -1 ? right = true : left = true);
      }
    }
    jakis->Kierunek(left, right);
  }
}











klasa Zasady::czy_cos_jest_na_drodze(Pionek * jakis, int x, int y)
{
  int i,j;
  Pionek ** pom;

  switch(jakis->GetName())
  {
    case NAZWAP::Kon :
    //dla konia to nie przeszkoda
      return klasa::nic;
      break;

    default:
      int ruch_x = x-jakis->GetPositionX();
      int ruch_y = y-jakis->GetPositionY();
      int vertical, horizontal, przemieszczenia;

      for(i=0;i<=15;i++)
      {
        // na poczatek sprawdzamy biale
        pom = Biale_pionki;
        for(j=0;j<=1;j++)
        {
          vertical = 0;
          horizontal = 0;
          przemieszczenia = 0;

          ruch_x != 0 ? przemieszczenia = ruch_x : przemieszczenia = ruch_y;
          przemieszczenia = abs(przemieszczenia);

          while(przemieszczenia > 1)
          {
            if(abs(ruch_x) != abs(ruch_y))
            {
              ruch_y > 0 ? vertical++ : (ruch_y != 0 ? vertical-- : vertical = 0);
              ruch_x > 0 ? horizontal++ : (ruch_x != 0 ? horizontal-- : horizontal = 0);
            }
            else
            {
              ruch_y > 0 ? vertical++ : (ruch_y != 0 ? vertical-- : vertical = 0);
              ruch_x > 0 ? horizontal++ : (ruch_x != 0 ? horizontal-- : horizontal = 0);
            }

            if((pom[i]->GetPositionX() == (jakis->GetPositionX() + horizontal)) &&
               (pom[i]->GetPositionY() == (jakis->GetPositionY() + vertical)))
            {
              if((jakis->GetColor() && pom[i]->GetColor()) || (!jakis->GetColor() && !pom[i]->GetColor()))
              {
                return klasa::ty;
              }
              else
              {
                return klasa::przeciwnik;
              }
            }
            przemieszczenia--;
          }
          //teraz czarne
          pom = Czarne_pionki;
        }
      }
      return klasa::nic;
      break;
  }
}






//analogicznie prawie jak wyzej

klasa Zasady::cos_na_tym_miejscu(Pionek * jakis, int x, int y)
{
  int i,j;

  Pionek** pom;

  for(i=0;i<=15;i++)
  {
    pom = Biale_pionki;
    for(j=0;j<=1;j++)
    {
      if((pom[i]->GetPositionX() == x) && (pom[i]->GetPositionY() == y))
      {
        if((jakis->GetColor() && pom[i]->GetColor()) || (!jakis->GetColor() && !pom[i]->GetColor()))
        {
          return klasa::ty;
        }
        else
        {
          return klasa::przeciwnik;
        }
      }
      pom = Czarne_pionki;
    }
  }
  return klasa::nic;
}







bool Zasady::sprawdz_czy_jest_szach(bool kolorKrola, int x, int y)
{
  Pionek ** pom;
  //wyznaczenie koloru

  kolorKrola ? pom = Czarne_pionki : pom = Biale_pionki;

  for(int i = 0; i<16; i++)
  {
    //z boku pionka
    SetKierunek(true, pom[i], x, y); 

    //czy przeciwnik moze isc do krola
    if(pom[i]->czy_moge_sie_ruszyc(x, y) && (czy_cos_jest_na_drodze(pom[i], x, y) == klasa::nic))  
      {
        return true;
      }
    
    SetKierunek(false, pom[i], -1, -1); 
  }

  return false;
}








bool Zasady::czy_moge_przesunac(Pionek * cos, int x, int y)
{
  SetKierunek(true, cos, -1, -1); 

  //przejmij klase tego co jest na wybranym miejscu 
  klasa na_moim_miejscu = cos_na_tym_miejscu(cos, x, y);

  if(cos->czy_moge_sie_ruszyc(x, y) && (czy_cos_jest_na_drodze(cos, x, y) == klasa::nic) && (na_moim_miejscu != klasa::ty) && (czy_kolej_bialych == cos->GetColor()))
  {
    SetKierunek(false, cos, -1, -1); 

    if(cos->GetName() == NAZWAP::Krol)
    {
      if(sprawdz_czy_jest_szach(cos->GetColor(), x, y))
        {
          return false;
        }
    }
    //co jak to Pion bo on bije inaczej
    if(cos->GetName() == NAZWAP::Pion)  
     {
        if(na_moim_miejscu == klasa::przeciwnik && (x - cos->GetPositionX() == 0))
        {
          return false;
        }
     }
    //w innym przypadku 
    if(na_moim_miejscu == klasa::przeciwnik)
    {
      zbij(x, y);
    }

    cos->SetPosition(x, y);

    zamiana_pionka(cos);
    czy_kolej_bialych = !czy_kolej_bialych;
    return true;
  }
  SetKierunek(false, cos, -1, -1); 
  return false;
}







void Zasady::zbij(int x, int y)
{
  Pionek ** pom;
  int i, j;

  pom = Biale_pionki;

  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 16; j++)
    {
      if((pom[j]->GetPositionX() == x) && (pom[j]->GetPositionY() == y))
      {
        pom[j]->umzyj();
      }
    }
    pom = Czarne_pionki;
  }
}







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////sprawdz
bool Zasady::czy_jest_szach_mat(bool kolorkrola)
{
  Pionek ** pom;
  Pionek ** pom2;

  int x, y;

  if(kolorkrola)
  {
    pom = Biale_pionki;
    pom2 = Czarne_pionki;
  }
  else
  {
    pom = Czarne_pionki;
    pom2 = Biale_pionki;
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(sprawdz_czy_jest_szach(pom[12]->GetColor(), pom[12]->GetPositionX(), pom[12]->GetPositionY()))
  {
    x = pom[12]->GetPositionX();
    y = pom[12]->GetPositionY();

  //mozliwy ruch krola 
    for(int i=-1;i<2;i++)
    {
      for(int j=-1;j<2;j++)
      {
        for(int k = 0; k < 16; k++)
        {
          if(!sprawdz_czy_jest_szach(kolorkrola, x+i, y+j) && cos_na_tym_miejscu(pom[12], x+i, y+j) != klasa::ty && (!pom2[k]->czy_moge_sie_ruszyc(x+i,y+j) || czy_cos_jest_na_drodze(pom2[k], x+i, y+j) != klasa::nic) && pom[12]->czy_moge_sie_ruszyc(x+i,y+j))
            {
              return false;
            }
        }
      }
    }
    return true;
  }
  return false;
}









Wynik Zasady::kto_wygral()
{
  bool biale = false;
  bool czarne = false;

  biale = czy_jest_szach_mat(true) || !Biale_pionki[12]->Getczy_gra_trwa();
  czarne = czy_jest_szach_mat(false) || !Czarne_pionki[12]->Getczy_gra_trwa();

  if(!biale && !czarne)
  {
    for(int i = 0; i < 16; i++)
    {
      if((Biale_pionki[i]->Getczy_gra_trwa() && (Biale_pionki[i]->GetName() != NAZWAP::Krol)) || (Czarne_pionki[i]->Getczy_gra_trwa() && (Czarne_pionki[i]->GetName() != NAZWAP::Krol)))
        return Wynik::Brak;
    }
    return Wynik::Remis;
  }

  if(biale)
    return Wynik::Czarne;

  if(czarne)
    return  Wynik::Biale;

  return Wynik::Brak;
}












bool Zasady::czy_pozycja_jest_cool(Pionek * jakis, int x, int y)
{
  //////////////////////////////////lepiej nie ruszac króla
  klasa KLASA;
  if(jakis->GetName() == NAZWAP :: Krol)
  {
    if(sprawdz_czy_jest_szach(jakis->GetColor(), x, y))
      return false;
  }

  SetKierunek(true, jakis, -1, -1); 
  KLASA = cos_na_tym_miejscu(jakis, x, y);

//czy cos jest na drodze ? i czy nie ma tam mnie, jak bedzie przeciwnik moge bic
  if(jakis->czy_moge_sie_ruszyc(x, y) && (czy_cos_jest_na_drodze(jakis, x, y) == klasa::nic) && KLASA != klasa::ty)
    {
      SetKierunek(false, jakis, -1, -1); 

      // one inaczej bija 
      if((jakis->GetName() == NAZWAP :: Pion) && (KLASA == klasa::przeciwnik))
      {
        if(jakis->GetPositionX() - x != 0)
        {
          return true;
        }
      }
      else
      {
        return true;
      }
    }

  SetKierunek(false, jakis, -1, -1);

  return false;
}









Pionek * Zasady::GetPionek(int x, int y)
{
  if((x >= 0) && (y >=0) && (x < 8) && (y < 8))
  {
    for(int i = 0; i < 16; i++)
    {
      if(Biale_pionki[i]->GetPositionX() == x && Biale_pionki[i]->GetPositionY() == y)
        {
          return Biale_pionki[i];
        }
      if(Czarne_pionki[i]->GetPositionX() == x && Czarne_pionki[i]->GetPositionY() == y)
        {
          return Czarne_pionki[i];
        }
    }
  }
  return niewiadomo;
}









/////////////////////////////////////////////////////////////////////////////////////
bool Zasady::mozliwosc_magicznego_ruchu(Pionek *cos, int x, int y)
{
  if((x >= 0) && (y >=0) && (x < 8) && (y < 8))
    if(cos_na_tym_miejscu(cos, x, y) == klasa::nic)
    {
      cos->odrodzenie();
      cos->SetPosition(x, y);
      return true;
    }

  return false;
}








///////////////////////////////////////////////////////////////////////////////////////////////////////
void Zasady::PlayBestMove(bool kolor)
{
  Pionek ** jakis;
  Waga_pionka * bestMoves;

  int values[16], n;
  bool result;

  if(kolor)
  {
    jakis = Biale_pionki;
    bestMoves = waga_bialych;
  }
  else
  {
    jakis = Czarne_pionki;
    bestMoves = waga_czarnych;
  }

  UpdateBestMoves();

  for(int i = 0; i < 16; i++)
  {
    if((bestMoves[i].maxx != -1) && (bestMoves[i].maxy != -1))
    {
      values[i] = bestMoves[i].Waga;
    }
    else
    {
      values[i] = -900000;
    }

  }

  n = sizeof(values)/sizeof(values[0]);
  sort(values, values + n);


  for(int i = 0; i < 16; i++)
  {
    if((bestMoves[i].Waga == values[15]) && (bestMoves[i].maxx != -1) && (bestMoves[i].maxy != -1))
    {
      result = czy_moge_przesunac(jakis[i], bestMoves[i].maxx, bestMoves[i].maxy);
      return;
    }
  }
}









void Zasady::UpdateBestMoves()
{
  int maxValue = -50;

  klasa KLASA;
  Waga_pionka  * pom_waga;
  Pionek ** pom;
////////////////////////////////////////////////////////////////
  for(int i = 0; i < 16; i++)
  {
    waga_bialych[i].maxx = -1;
    waga_bialych[i].maxy = -1;
    waga_bialych[i].Waga = -20;
    waga_czarnych[i].maxx = -1;
    waga_czarnych[i].maxy = -1;
    waga_czarnych[i].Waga = -20;
  }

  //Oblicza najlepsze ruchy dla każdego kawałka
  for(int i = 0; i < 16; i++)
  {
    pom_waga = waga_bialych;
    pom = Biale_pionki;
    for(int a = 0;a < 2; a++)
    {
      for(int x = 0; x < 8; x++)
      {
        for(int y = 0; y < 8; y++)
        {
          if(czy_pozycja_jest_cool(pom[i], x, y))
          {
            KLASA = cos_na_tym_miejscu(pom[i], x, y);
            KLASA == klasa::przeciwnik ? maxValue = GetPionek(x, y)->Getwartosc() - pom[i]->Getwartosc() : maxValue = - pom[i]->Getwartosc();
            if(maxValue > pom_waga[i].Waga)
            {
              pom_waga[i].maxx = x;
              pom_waga[i].maxy = y;
              pom_waga[i].Waga = maxValue;
            }
          }
        }
      }
      maxValue = -10;
      pom_waga = waga_czarnych;
      pom = Czarne_pionki;
    }
  }
}


Waga_pionka Zasady::GetPionka_BestMove(Pionek * jakis)
{
  Pionek ** pom;
  Waga_pionka * waaaga;

  UpdateBestMoves();

  if(jakis->GetColor())
  {
    pom = Biale_pionki;
    waaaga = waga_bialych;
  }
  else
  {
    pom = Czarne_pionki;
    waaaga = waga_czarnych;
  }

  for(int i = 0; i < 16; i++)
  {
    if((jakis->GetPositionX() == pom[i]->GetPositionX()) && (jakis->GetPositionY() == pom[i]->GetPositionY()))
      {
        return waaaga[i];
      }
  }
}






void Zasady::zamiana_pionka(Pionek * jakis)
{
  int y,x;
  bool color;
  Pionek ** pom;

  if(jakis->GetName() == NAZWAP::Pion)
  {
    color = jakis->GetColor();

    y = jakis->GetPositionY();
    if((color && (y == 0)) || (!color && (y == 7)))
    {
      x = jakis->GetPositionX();
      color ? pom = Biale_pionki : pom = Czarne_pionki;

      for(int i = 0; i < 16; i++)
      {
        if((pom[i]->GetPositionX() == x) && (pom[i]->GetPositionY() == y))
        {
          // bez wariantu wybrania, zawsze jest to krolowa!
          pom[i] = new Krolowa(color, x, y);
          return;
        }
      }
    }
  }
}







void Zasady::SetKolejke_pionka(bool czyja_kolej)
{
  this->czy_kolej_bialych = czyja_kolej;
  
}



bool Zasady::Getkolejke_pionka()
{
  return this->czy_kolej_bialych;
}


void Zasady::wyczysc_wszystko()
{
  int i;
  for(i = 0; i < 16; i++)
  {
    Biale_pionki[i]->umzyj();
    Czarne_pionki[i]->umzyj();
  }
}
