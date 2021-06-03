
#ifndef KON_HPP
#define KON_HPP

#include "pionek.hpp"
#include <iostream>
#include <string>

using namespace std;

class Kon : public Pionek
{
  public:
    Kon(bool czy_jestem_bialy, int X, int Y);
    ~Kon();
    bool czy_moge_sie_ruszyc(int X, int Y);
};

#endif