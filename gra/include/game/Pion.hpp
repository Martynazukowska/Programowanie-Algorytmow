#ifndef PION_HPP
#define PION_HPP

#include "pionek.hpp"

class Pion : public Pionek
{
    bool wrog_po_prawej = false;
    bool wrog_po_lewej = false;

  public:
    Pion(bool czy_jestem_bialy, int x, int y);
    ~Pion();
    bool czy_moge_sie_ruszyc(int pom, int pom2);
    void SetDiagonalEnemy(bool pom , bool pom2);
};

#endif
