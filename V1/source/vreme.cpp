#include "vreme.hpp"

int Vreme::kolikoDanaImaMesec(int mesec)
{
	if (mesec == 2)
		return 0; // februar ima uvek 28 dana
	else if (mesec == 1 || mesec == 3 || mesec == 5 || mesec == 7 || mesec == 10 || mesec == 12)
		return 2; // ima 31 dan
	else
		return 1; // ima 30 dana
}

Vreme::Vreme(int sat, int minut, int dan, int mesec, int godina) : h(sat), min(minut), d(dan), mes(mesec), g(godina)
{
	if (mesec > 12 || mesec < 1) {
		throw std::out_of_range("Meseci su van opsega!");
	}
	if (sat > 23 || sat < 0) {
		throw std::out_of_range("Sati su van opsega!");
	}
	if (minut > 59 || minut < 0) {
		throw std::out_of_range("Minuti su van opsega!");
	}
	if (godina < 0) {
		throw std::out_of_range("Godina mora biti pozitivan broj!");
	}
	if (mesec == 1 || mesec == 3 || mesec == 5 || mesec == 7 || mesec == 8 || mesec == 10 || mesec == 12) {
		if (dan > 31) {
			throw std::out_of_range("Dani su van opsega!");
		}
	}
	else if (mesec == 4 || mesec == 6 || mesec == 9 || mesec == 11) {
		if (dan > 30) {
			throw std::out_of_range("Dani su van opsega!");
		}
	}
	else {
		if (dan > 28) {
			throw std::out_of_range("Dani su van opsega!");
		}
	}
}

Vreme::Vreme(const Vreme& v)
{
	this->h = v.h;
	this->min = v.min;
	this->d = v.d;
	this->mes = v.mes;
	this->g = v.g;
}

Vreme& Vreme::operator=(const Vreme& vreme)
{
	if (this != &vreme)
	{
		h = vreme.h;
		min = vreme.min;
		d = vreme.d;
		mes = vreme.mes;
		g = vreme.g;
	}

	return *this;
}

bool Vreme::operator==(Vreme& vreme)
{
	if (this->dohvatiSat() != vreme.dohvatiSat())
		return false;
	else if (this->dohvatiMinut() != vreme.dohvatiMinut())
		return false;
	else if (this->dohvatiDan() != vreme.dohvatiDan())
		return false;
	else if (this->dohvatiMesec() != vreme.dohvatiMesec())
		return false;
	else if (this->dohvatiGodinu() != vreme.dohvatiGodinu())
		return false;
	else
		return true;
}
bool Vreme::operator<(Vreme& vreme)
{
	// Ako je godina manja, npr 2020 > 2024, automatksi je tačan ceo izraz
	if (vreme.dohvatiGodinu() < this->dohvatiGodinu())
		return true;
	// Ako su godine jednake
	else if (vreme.dohvatiGodinu() == this->dohvatiGodinu())
	{ // Ako je prvi mesec veći od drugog npr, januar je pre marta
		if (vreme.dohvatiMesec() < this->dohvatiMesec())
			return true;
		// Ako su meseci jednaki
		else if (vreme.dohvatiMesec() == this->dohvatiMesec())
		{
			// Ako je prvi dan veći od drugo npr, 3. je pre 17.
			if (vreme.dohvatiDan() < this->dohvatiDan())
				return true;
			else if (vreme.dohvatiDan() == this->dohvatiDan())
			{
				// Ako je prvi sat veći od drugog
				if (vreme.dohvatiSat() < this->dohvatiSat())
					return true;
				else if (vreme.dohvatiSat() == this->dohvatiSat())
				{
					if (vreme.dohvatiMinut() < this->dohvatiMinut())
						return true;
					else
						return false;
				}
				// Ako je drugi sat veći od prvog
				else
					return false;
			}
			else
				return false;
		}
		// Ako je drugi mesec veći od prvog
		else
			return false;
	}
	// Ako je godina veća, npr 2020 < 2018, automatski je netačan ceo izraz
	else
		return false;
}
void Vreme::operator+=(int minuti)
{
	if (dohvatiMinut() + minuti >= 60)
	{
		int noviMinuti = (dohvatiMinut() + minuti) % 60;
		int dodatiSati = (dohvatiMinut() + minuti) / 60;
		postaviMinut(noviMinuti);
		if (dohvatiSat() + dodatiSati >= 24)
		{
			int noviSati = (dohvatiSat() + dodatiSati) % 24;
			int dodajDane = (dohvatiSat() + dodatiSati) / 24;
			int kolikoDana = kolikoDanaImaMesec(dohvatiMesec());
			postaviSat(noviSati);
			if (kolikoDana == 0)
			{
				if (dohvatiDan() + dodajDane > 28)
				{
					int noviDani = (dohvatiDan() + dodajDane) % 28; // Pretpostavka da nećemo dodati više od 28 dana tj nećemo preći za 2 meseca vise
					if (dohvatiMesec() + 1 > 12)
					{
						postaviMesec(1);
						postaviGodinu(dohvatiGodinu() + 1);
					}
					else
					{
						postaviMesec(dohvatiMesec() + 1);
					}
					postaviDan(noviDani);
				}
				else
				{
					postaviDan(dohvatiDan() + dodajDane);
				}
			}
			else if (kolikoDana == 1)
			{
				if (dohvatiDan() + dodajDane > 30)
				{
					int noviDani = (dohvatiDan() + dodajDane) % 30; // Pretpostavka da nećemo dodati više od 30 dana tj nećemo preći za 2 meseca vise
					if (dohvatiMesec() + 1 > 12)
					{
						postaviMesec(1);
						postaviGodinu(dohvatiGodinu() + 1);
					}
					else
					{
						postaviMesec(dohvatiMesec() + 1);
					}
					postaviDan(noviDani);
				}
			}
			else
			{
				if (dohvatiDan() + dodajDane > 30)
				{
					int noviDani = (dohvatiDan() + dodajDane) % 31; // Pretpostavka da nećemo dodati više od 31 dana tj nećemo preći za 2 meseca vise
					if (dohvatiMesec() + 1 > 12)
					{
						postaviMesec(1);
						postaviGodinu(dohvatiGodinu() + 1);
					}
					else
					{
						postaviMesec(dohvatiMesec() + 1);
					}
					postaviDan(noviDani);
				}
				else
				{
					postaviDan(dohvatiDan() + dodajDane);
				}
			}
		}
		else
			postaviSat(dohvatiSat() + dodatiSati);
	}
	else
		postaviMinut(dohvatiMinut() + minuti);
}

std::ostream& operator<<(std::ostream& os, Vreme& vreme)
{
	return os << vreme.dohvatiSat() << ":" << vreme.dohvatiMinut() << "-" << vreme.dohvatiDan() << "." << vreme.dohvatiMesec() << "." << vreme.dohvatiGodinu() << ".";
}