#include "guma.hpp"

bool Guma::operator==(Guma &guma)
{
    return dohvatiOznaku() == guma.dohvatiOznaku() && dohvatiSirinu() == guma.dohvatiSirinu() && dohvatiVisinu() == guma.dohvatiVisinu() && dohvatiPrecnik() == guma.dohvatiPrecnik();
}

std::ostream &operator<<(std::ostream &os, Guma &guma)
{
    return os << guma.dohvatiSirinu() << "/" << guma.dohvatiVisinu() << "R/" << guma.dohvatiPrecnik() << "-" << guma.dohvatiOznaku() << "@" << guma.dohvatiVreme() << "==" << guma.dohvatiCenu();
}