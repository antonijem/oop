#ifndef SELEKTOR_HPP
#define SELEKTOR_HPP
#include "lista.hpp"


class Selektor {
private:
	static int id;
	Lista<string>* kolone;
public:
	Selektor(Lista<string>* k) :kolone(k) { id++; }
	Lista<string>* dohvatiKolone() { return kolone; }
	virtual string dohvatiOpis() = 0;
	bool operator==(Selektor& selektor) {
		kolone->postaviPrviNaTekuc();
		selektor.dohvatiKolone()->postaviPrviNaTekuc();
		do
		{
			if (kolone->dohvatiTekuciElement() != selektor.dohvatiKolone()->dohvatiTekuciElement())
				return false;

		} while (kolone->sledeciElement() && selektor.dohvatiKolone()->sledeciElement());
		return true;
	}
};

#endif // !SELEKTOR_HPP
