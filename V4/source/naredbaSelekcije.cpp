#include "naredbaSelekcije.hpp"

bool NaredbaSelekcije::proveraKolona()
{
    while (selektor->dohvatiKolone()->sledeciElement()) {
        if (!this->dohvatiTabelu()->sadrziKolonu(*selektor->dohvatiKolone()->dohvatiTekuciElement()))
            return false;
    }
    return true;
}

string NaredbaSelekcije::dohvatiOpis()
{
    string ret = "SELECT ";
    ret += selektor->dohvatiOpis();
    ret += " FROM ";
    ret += dohvatiTabelu()->dohvatiNaziv();
    return ret;
}
