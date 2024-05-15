#include "polje.hpp"

Polje Polje::dohvatiPolje(int k, int r)
{
    if (kolona + k > Oznaka::J || kolona + k < Oznaka::A || red + r < 0 || red + r > 10)
    {
        cout << "Greska:Pomeraj izlazi van opsega polja!" << endl;
    }

    Polje temp(Oznaka(kolona + k), red + r);
    return temp;
}

bool Polje::operator==(Polje &polje)
{
    return kolona == polje.kolona && red == polje.red;
}