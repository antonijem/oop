#ifndef FUNKCIJA_HPP
#define FUNKCIJA_HPP

#include "lista.hpp"
#include "parametar.hpp"
#include <string>


using namespace std;

class Funkcija
{
private:
    string ime;
    Lista<Parametar> *parametri;

public:
    Funkcija(string i, Lista<Parametar> *p) : ime(i), parametri(p) {}
    void dodajParametar(Parametar *param) { *parametri += param; }
    int dohvatiBrojParametara() { return parametri->dohvatiBrojElemenata(); }
    const Parametar& dohvatiParametar(int indeks) const { return (*parametri)[indeks]; }
    friend ostream &operator<<(ostream &os, Funkcija &fun)
    {
        os << fun.ime;
        os << "(";
        int brojParam = fun.dohvatiBrojParametara();
        for (int i = 0; i < brojParam; i++)
        {
            os << fun.dohvatiParametar(i);
            if (i != brojParam - 1)
                os << ", ";
        }
        os << ")";
        return os;
    }
};

#endif