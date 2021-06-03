
#ifndef GONIEC_HPP
#define GONIEC_HPP

#include "game/pionek.hpp"

#include <iostream>
#include <string>

using namespace std;


class Goniec : public Pionek
{
  public:
    Goniec(bool czy_jestem_bialy, int x, int y);
    ~Goniec();
    bool czy_moge_sie_ruszyc(int x, int y);
};

#endif
