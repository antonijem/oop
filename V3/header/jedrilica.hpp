#ifndef JEDRILICA_HPP
#define JEDRILICA_HPP

#include "figura.hpp"

class Jedrilica : public Figura
{
private:
	char oznaka;
	bool inicijalizujSvaPolja();
public:
	Jedrilica(Polje* centar) : Figura(centar), oznaka('H') { inicijalizujSvaPolja(); }
	char dohvatiOznaku();
};

#endif