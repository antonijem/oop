#include "jedrilica.hpp"

bool Jedrilica::inicijalizujSvaPolja()
{
    for (int i = -1; i < 2; i++)
    {
        Polje *levo = new Polje(dohvatiCentar()->dohvatiPolje(-1, i));
        Polje *desno = new Polje(dohvatiCentar()->dohvatiPolje(1, i));
        *dohvatiPolja() += levo;
        *dohvatiPolja() += desno;
    }
    return true;
}

char Jedrilica::dohvatiOznaku()
{
    return oznaka;
}
