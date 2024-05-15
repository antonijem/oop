#ifndef LISTA_HPP
#define LISTA_HPP

#include<string>
using namespace std;

template<typename T>
class Cvor {
public:
	T* podatak;
	Cvor<T>* sledeci;

	Cvor(T* p) :podatak(p), sledeci(nullptr) {}
};

template<typename T>
class Lista {
private:
	Cvor<T>* glava;
	Cvor<T>* tekuciElement;
public:

	Lista() :glava(nullptr), tekuciElement(nullptr) {}
	Cvor<T>* dohvatiPrviElement() { return glava; }
	Cvor<T>* dohvatiPoslednjiElement() {
		Cvor<T>* iter = glava;
		while (iter->sledeci)
		{
			iter = iter->sledeci;
		}
		return iter;
	}

	void operator+=(T* podatak) {
		Cvor<T>* noviCvor = new Cvor<T>(podatak);
		if (!glava)
			glava = noviCvor;
		else {
			Cvor<T>* poslednji = dohvatiPoslednjiElement();
			poslednji->sledeci = noviCvor;
		}
	}

	void operator+=(Lista& lista) {
		if (!glava) {
			glava = lista.dohvatiPrviElement();
		}
		else {
			dohvatiPoslednjiElement()->sledeci = lista.dohvatiPrviElement();
		}
	}

	void postaviPrviNaTekuc() {
		if (glava) {
			tekuciElement = glava;
		}
	}

	bool sledeciElement() {
		if (!tekuciElement) {
			tekuciElement = glava;
			return true;
		}
		else if (tekuciElement->sledeci) {
			tekuciElement = tekuciElement->sledeci;
			return true;
		}
		else {
			return false;
		}
	}

	const T* dohvatiTekuciElement() {
		return tekuciElement->podatak;
	}

	bool daLiJePrazna() {
		if (!glava)
			return true;

		return false;
	}

	bool daLiSadrziPodatak(const T* podatak) {
		if (daLiJePrazna()) {
			return false;
		}
		Cvor<T>* iter = glava;
		do
		{

			if (static_cast<string>(*iter->podatak) == static_cast<string>(*podatak))
				return true;
			iter = iter->sledeci;
		} while (iter);

		return false;
	}

	string dohvatiOpis(string separator) {
		string ret;
		Cvor<T>* iter = glava;
		while (iter->sledeci) {
			ret += *iter->podatak;
			ret += separator;
			iter = iter->sledeci;
		}
		ret += *iter->podatak;
		return ret;

	}
};

#endif // !LISTA_HPP
