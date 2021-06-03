#ifndef WIEZA_HPP
#define WIEZA_HPP

#include "pionek.hpp"
#include <iostream>
#include <string>

using namespace std;

class Wieza : public Pionek
{
  public:
    Wieza(bool czy_jestem_bialy , int X, int Y);
    ~Wieza();
    bool czy_moge_sie_ruszyc(int, int);
};

#endif
