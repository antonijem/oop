#ifndef BIBLIOTEAK_HPP
#define BIBLIOTEAK_HPP

#include "funkcija.hpp"

using namespace std;

class Biblioteka {
private:
	Lista<Funkcija>* funkcije;
public:
	Biblioteka(Lista<Funkcija>* f) :funkcije(f) {}

	void dodajFunkciju(Funkcija* fun) { *funkcije += fun; }
	Funkcija& operator[](int indeks) {
		if (indeks <0 || indeks > funkcije->dohvatiBrojElemenata() - 1) {
			cout << "Greska: Indeks van opsega!";
			throw out_of_range("Van ospega");
		}
		return (*funkcije)[indeks];
	}

	friend ostream& operator<<(ostream& os, Biblioteka& bibl) {
		for (int i = 0; i < bibl.funkcije->dohvatiBrojElemenata(); i++) {
			os << bibl[i] << endl;
		}
		return os;
	}
};

#endif // !BIBLIOTEAK_HPP
