#include "lista.hpp"
#include "parametar.hpp"
#include "funkcija.hpp"
#include "biblioteka.hpp"

using namespace std;

int main()
{
    Lista<Parametar> *lista = new Lista<Parametar>;
    Parametar *p1 = new Parametar("param", Tip::STRING);
    Parametar *p2 = new Parametar("param2", Tip::STRING);
    Argument<int> *arg = new Argument<int>("arg", Tip::INT, 6);
    cout << *arg << endl;
    if (p1 == p2)
        cout << "Isti su";
    *lista += p1;
    *lista += p2;
    *lista += arg;
    Funkcija *f1 = new Funkcija("fun", lista);
    Funkcija *f2 = new Funkcija("f2", lista);
    Lista<Funkcija>* listaF = new Lista<Funkcija>;
    Biblioteka b(listaF);
    b.dodajFunkciju(f1);
    b.dodajFunkciju(f2);
    cout << b;
    return 0;
}
