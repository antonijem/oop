#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

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

    T *operator[](int indeks)
    {
        if (indeks < 0 || indeks > brojElemenata - 1)
        {
            cout << "Greska:Indeks van opsega." << endl;
            throw out_of_range("Van opsega");
        }
        Cvor<T> *iter = glava;
        for (int i = 0; i < indeks; i++)
        {
            iter = iter->sledeci;
        }
        return iter->podatak;
    }

    bool operator()(int i)
    {
        if (i < 0 || i > brojElemenata - 1)
        {
            cout << "Greska:Indeks van opsega." << endl;
            throw out_of_range("Van opsega");
        }
        Cvor<T> *iter = glava;
        for (int j = 0; j < i; j++)
        {
            iter = iter->sledeci;
        }
        if (iter->podatak == nullptr)
            return false;
        else
            return true;
    }
};

#endif