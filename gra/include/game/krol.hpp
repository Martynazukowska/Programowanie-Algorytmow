#ifndef KROL_HPP
#define KROL_HPP

#include "pionek.hpp"
#include <iostream>
#include <string>

using namespace std;

class Krol : public Pionek
{
  public:
    Krol(bool czy_jestem_bialy, int X, int Y);
    ~Krol();
    bool czy_moge_sie_ruszyc(int X, int Y);
};

#endif
