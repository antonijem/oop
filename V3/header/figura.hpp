#ifndef FIGURA_HPP
#define FIGURA_HPP

#include "polje.hpp"
#include "lista.hpp"

class Figura
{
private:
    Polje *centar;
    Lista<Polje> polja;
    virtual bool inicijalizujSvaPolja() = 0;

public:
    Figura(Polje *c) : centar(c) {}
    Figura(Figura &fig) : centar(fig.centar), polja(fig.polja) {}
    Figura &operator=(Figura &fig);
    Lista<Polje> *dohvatiPolja() { return &polja; }
    Polje *dohvatiCentar() { return centar; }
    bool gadjanje(Polje *p);
    bool operator&(Figura &fig);
    bool operator==(Figura &fig);
    virtual char dohvatiOznaku() = 0;
};

#endif