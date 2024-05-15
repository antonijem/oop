#include "lista.hpp"

template <typename T>
void Lista<T>::dodajNaKraj(T *podatak)
{
    Cvor<T> *novi = new Cvor<T>(*podatak);
    if (!glava)
    {
        glava = novi;
    }
    else
    {
        Cvor<T> *iter = glava;
        while (iter->sledeci)
        {
            iter = iter->sledeci;
        }
        iter->sledeci = novi;
    }
    brojElemenata++;
}
template <typename T>
T &Lista<T>::operator[](int indeks)
{
    if (brojElemenata - 1 < indeks || indeks < 0)
    {
        std::cout << "Greska: Indeksiranje van opsega!" << std::endl;
        return nullptr;
    }
    Cvor<T> *pod = glava;
    for (int i = 0; i < indeks; i++)
    {
        pod = pod->sledeci;
    }
    return pod->podatak;
}

template <typename T>
void Lista<T>::izbaciElement(int indeks)
{
    if (brojElemenata - 1 < indeks || indeks < 0)
    {
        std::cout << "Greska: Indeksiranje van opsega!" << std::endl;
        return;
    }
    Cvor<T> *podatak = glava;
    for (int i = 0; i < indeks - 1; i++)
    {
        podatak = podatak->sledeci;
    }
    Cvor<T> *brisanje = podatak->sledeci;
    podatak->sledeci = brisanje->sledeci;
    delete brisanje;
}