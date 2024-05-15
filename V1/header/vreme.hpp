#ifndef VREME_HPP
#define VREME_HPP
#include <iostream>
#include <stdexcept>
// Ne radim proveru na prestupne godine, februar ima uvek 28 dana

class Vreme
{
private:
	int h, min, d, mes, g;

public:
	Vreme(int sat, int minut, int dan, int mesec, int godina);
	Vreme(const Vreme& v);
	Vreme& operator=(const Vreme& vreme);
	int dohvatiSat() { return h; }
	int dohvatiMinut() { return min; }
	int dohvatiDan() { return d; }
	int dohvatiMesec() { return mes; }
	int dohvatiGodinu() { return g; }

	void postaviSat(int sat) { h = sat; }
	void postaviMinut(int minut) { min = minut; }
	void postaviDan(int dan) { d = dan; }
	void postaviMesec(int mesec) { mes = mesec; }
	void postaviGodinu(int godina) { g = godina; }
	int kolikoDanaImaMesec(int mesec); //Vraca 0 za februar, 1 za 30, 2 za 31 dan

	bool operator==(Vreme& vreme);
	bool operator<(Vreme& vreme);
	void operator+=(int minuti);
	friend std::ostream& operator<<(std::ostream& os, Vreme& vreme);
};

#endif