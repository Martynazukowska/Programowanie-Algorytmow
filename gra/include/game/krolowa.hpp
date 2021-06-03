#ifndef KROLOWA_HPP
#define KROLOWA_HPP

#include <iostream>
#include <string>
#include "pionek.hpp"

using namespace std;


class Krolowa : public Pionek
{
  public:
    Krolowa(bool czy_jestem_bialy, int X, int Y );
    ~Krolowa();
    bool czy_moge_sie_ruszyc(int X, int Y);
};

#endif
