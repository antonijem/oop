#include "vreme.hpp"
#include "letnja.hpp"
#include "zimska.hpp"
#include "svesezone.hpp"
#include "lista.hpp"

using namespace std;

int main()
{
    Vreme v1(23, 45, 3, 3, 2024);
    SveSezone *s1 = new SveSezone(50, 190, 17, 1.6, 30000, v1);
    Letnja *l1 = new Letnja(10, 300, 19, 3, 40000, v1);
    Lista<Guma> l;
    cout << *l1 << endl;
    l.dodajNaKraj(l1);
    l.dodajNaKraj(s1);
    cout << l[1];
}