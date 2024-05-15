#ifndef SVESEZONE_HPP
#define SVESEZONE_HPP
#include "guma.hpp"

class SveSezone : public Guma
{
public:
    SveSezone(int sirina, int visina, int precnik, double dubina, int cena, Vreme datumProizvodnje) : Guma(sirina, visina, precnik, dubina, cena, datumProizvodnje) {}
    char dohvatiOznaku() { return 'A'; }
    bool odgovarajucaDubina();
};

#endif
