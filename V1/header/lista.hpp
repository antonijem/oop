#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>

template <typename T>
class Cvor
{
public:
    T *podatak;
    Cvor<T> *sledeci;
    Cvor(T *p, Cvor<T> *s = nullptr) : podatak(p), sledeci(s) {}
};

template <typename T>
class Lista
{
private:
    Cvor<T> *glava;
    int brojElemenata;

public:
    Lista() : glava(nullptr), brojElemenata(0) {}
    ~Lista()
    {
        while (glava)
        {
            Cvor<T> *temp = glava;
            glava = glava->sledeci;
            delete temp;
        }
    }
    void dodajNaKraj(T *podatak)
    {
        Cvor<T> *novi = new Cvor<T>(podatak);
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
    int dohvatiBrojElemenata() { return brojElemenata; }
    T &operator[](int indeks)
    {
        if (brojElemenata - 1 < indeks || indeks < 0)
        {
            std::cout << "Greska: Indeksiranje van opsega!" << std::endl;
            throw std::out_of_range("Indeksiranje van opsega!");
        }
        Cvor<T> *pod = glava;
        for (int i = 0; i < indeks; i++)
        {
            pod = pod->sledeci;
        }
        return *(pod->podatak);
    }
    void izbaciElement(int indeks)
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
};

#endif
