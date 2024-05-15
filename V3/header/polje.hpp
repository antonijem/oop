#ifndef POLJE_HPP
#define POLJE_HPP

#include <stdexcept>
#include <iostream>
using namespace std;

enum Oznaka
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J
};

class Polje
{
private:
    Oznaka kolona;
    int red;

public:
    Polje(Oznaka k, int r) : kolona(k)
    {
        if (r < 0 || r > 10)
        {
            cout << "Greska:Red je van opsega!";
            throw out_of_range("Van opsega");
        }
        else
            red = r;
    }

    Polje dohvatiPolje(int k, int r);
    bool operator==(Polje &polje);
};

#endif