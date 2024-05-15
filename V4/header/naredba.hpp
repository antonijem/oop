#ifndef NAREDBA_HPP
#define NAREDBA_HPP

#include "selektor.hpp"
#include "tabela.hpp"

class Naredba {
private:
	Tabela* tabela;
	Naredba(const Naredba& naredba) {}
	Naredba& operator=(const Naredba& naredba) {}
public:
	Naredba(Tabela* t) :tabela(t) {}
	virtual Selektor* dohvatiSelektor() = 0;
	virtual string dohvatiOpis() = 0;
	Tabela* dohvatiTabelu() { return tabela; }
	//Nije mi najjasnija ideja sa ovim operatorom?
	operator string() {
		return dohvatiOpis();
	}
};

#endif // !NAREDBA_HPP
