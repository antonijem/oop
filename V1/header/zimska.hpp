#ifndef ZIMSKA_HPP
#define ZIMSKA_HPP
#include "guma.hpp"

class Zimska : public Guma
{
public:
    Zimska(int sirina, int visina, int precnik, double dubina, int cena, Vreme datumProizvodnje) : Guma(sirina, visina, precnik, dubina, cena, datumProizvodnje) {}
    char dohvatiOznaku() { return 'Z'; }
    bool odgovarajucaDubina();
};

#endif
