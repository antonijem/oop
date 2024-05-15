#ifndef SELEKTOR_KOLONA_HPP
#define SELEKTOR_KOLONA_HPP

#include "selektor.hpp"

class Selektor_Kolona :public Selektor {
public:
	Selektor_Kolona(Lista<string>* kolone) :Selektor(kolone) {}
	string dohvatiOpis() { return dohvatiKolone()->dohvatiOpis(","); }
};

#endif // !SELEKTOR_KOLONA_HPP
