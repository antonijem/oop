#ifndef LETNJA_HPP
#define LETNJA_HPP
#include "guma.hpp"

class Letnja : public Guma
{
public:
    Letnja(int sirina, int visina, int precnik, double dubina, int cena, Vreme datumProizvodnje) : Guma(sirina, visina, precnik, dubina, cena, datumProizvodnje) {}
    char dohvatiOznaku() { return 'L'; }
    bool odgovarajucaDubina();
};

#endif
