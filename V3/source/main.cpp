#include "polje.hpp"
#include "lista.hpp"
#include "jedrilica.hpp"

int main()
{
	Polje* c1 = new Polje(Oznaka::D, 5);
	Polje* c2 = new Polje(Oznaka::E, 4);
	Polje* c3 = new Polje(Oznaka::G, 7);
	Jedrilica* j1 = new Jedrilica(c1);
	Jedrilica* j2 = new Jedrilica(c2);
	Jedrilica* j3 = new Jedrilica(c3);

	Lista<Jedrilica> jedrilice;
	jedrilice += j1;
	jedrilice += j2;
	jedrilice += j3;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 3; j++) {
			if (i != j && *jedrilice[i]&*jedrilice[j]) {
				cout << "Preklapaju se jedirlice " << i+1 << " i " << j+1 << endl;
			}
		}
	}


	return 1;
}