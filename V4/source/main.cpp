#include "tabela.hpp"
#include "selektor_kolona.hpp"
#include <iostream>
#include "naredbaSelekcije.hpp"

int main() {
	Lista<string> *lista = new Lista<string>;
	string s1 = "ime";
	string s2 = "prezime";
	string s3 = "zanimanje";
	*lista += &s1;
	*lista += &s2;
	*lista += &s3;
	string naziv = "Osoba";
	
	Tabela *t = new Tabela(naziv, lista);
	Selektor_Kolona *s = new Selektor_Kolona(lista);
	
	NaredbaSelekcije ns(t,s);
	cout << ns.dohvatiOpis();

	return 0;
}