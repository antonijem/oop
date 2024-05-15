#ifndef TABELA_HPP
#define TABELA_HPP

#include "lista.hpp"

class Tabela {
private:
	string naziv;
	Lista<string>* kolone;
public:
	Tabela(string n, Lista<string>* k) :naziv(n), kolone(k) {}

	string dohvatiNaziv() { return naziv; }
	Lista<string>* dohvatiKolone() { return kolone; }
	bool sadrziKolonu(string naziv);
	bool sadrziListu(Lista<string>* lista);
};

#endif // !TABELA_HPP
