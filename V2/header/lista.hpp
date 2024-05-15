#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include <stdexcept>

template <typename T>
class Cvor
{
public:
    T *podatak;
    Cvor<T> *sledeci;
    Cvor(T *p) : podatak(p), sledeci(nullptr) {}
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
    void operator+=(T *podatak)
    {
        Cvor<T> *noviCvor = new Cvor<T>(podatak);
        if (!glava)
        {
            glava = noviCvor;
        }
        else
        {
            Cvor<T> *iter = glava;
            while (iter->sledeci)
            {
                iter = iter->sledeci;
            }
            iter->sledeci = noviCvor;
        }
        brojElemenata++;
    }

    int dohvatiBrojElemenata() { return brojElemenata; }
    T &operator[](int indeks)
    {
        if (indeks < 0 || indeks > brojElemenata - 1)
        {
            std::cout << "Greska: Indeks van opsega!";
            std::out_of_range("Indeks van opsega!");
        }
        if (indeks == 0)
            return *glava->podatak;
        Cvor<T> *iter = glava;
        for (int i = 0; i < indeks; i++)
        {
            iter = iter->sledeci;
        }
        return *iter->podatak;
    }
};
#endif