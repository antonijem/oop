#ifndef NAREDBA_SELEKCIJE_HPP
#define NAREDBA_SELEKCIJE_HPP

#include "naredba.hpp"
#include <stdexcept>
#include <iostream>

class NaredbaSelekcije :public Naredba {
private:
	Selektor* selektor;
	bool proveraKolona();
public:
	NaredbaSelekcije(Tabela* tabela, Selektor* s) :Naredba(tabela), selektor(s) {
		if (!proveraKolona()) {
			std::cout << "Greska:Tabela ne sadrzi sve kolone koje pokusavate da selektujete.";
			throw std::exception("Ne postojece kolone su selektovane");
		}
	}

	Selektor* dohvatiSelektor() { return selektor; }
	string dohvatiOpis();
};

#endif // !NAREDBA_SELEKCIJE_HPP
