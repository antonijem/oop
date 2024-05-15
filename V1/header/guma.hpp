#ifndef GUMA_HPP
#define GUMA_HPP

#include "vreme.hpp"

class Guma
{
private:
    int s, v, p, c;
    double d;
    Vreme dp;
    Guma(const Guma &guma);
    Guma &operator=(Guma &guma) {}

public:
    Guma(int sirina, int visina, int precnik, double dubina, int cena, Vreme datumProizvodnje) : s(sirina), v(visina), p(precnik), d(dubina), c(cena), dp(datumProizvodnje) {}
    int dohvatiSirinu() { return s; }
    int dohvatiVisinu() { return v; }
    int dohvatiPrecnik() { return p; }
    double dohvatiDubinu() { return d; }
    int dohvatiCenu() { return c; }
    Vreme& dohvatiVreme() { return dp; }
    Guma& operator--(int dummy) { d -= 0.1; }
    virtual char dohvatiOznaku() = 0;
    virtual bool odgovarajucaDubina() = 0;
    bool operator==(Guma &guma);
    friend std::ostream &operator<<(std::ostream &os, Guma &guma);
};

#endif