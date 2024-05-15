#include "tabela.hpp"

bool Tabela::sadrziKolonu(string naziv)
{
    if (kolone->daLiSadrziPodatak(&naziv))
        return true;
    return false;
}

bool Tabela::sadrziListu(Lista<string>* lista)
{
    while (lista->sledeciElement())
    {
        if (!kolone->daLiSadrziPodatak(lista->dohvatiTekuciElement())) {
            return false;
        }
    }
    
    return false;
}
