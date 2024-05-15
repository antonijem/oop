#ifndef PARAMETAR_HPP
#define PARAMETAR_HPP

#include <iostream>
#include <string>
#include <exception>

using namespace std;

enum Tip
{
    INT,
    FLOAT,
    STRING
};

class Parametar
{
private:
    string ime;
    Tip tip;
    string vratiTip() const { return tip == Tip::INT ? "int" : (tip == Tip::FLOAT ? "float" : "string"); }

public:
    Parametar(string i, Tip t) : ime(i), tip(t) {}
    bool operator==(Parametar &param) { return ime == param.ime && tip == param.tip; }
    virtual std::ostream &print(std::ostream &os) const { return os << vratiTip() << " " << ime; }
    friend std::ostream &operator<<(std::ostream &os, const Parametar &param) { return param.print(os); }
};

template <typename T>
class Argument : public Parametar
{
private:
    T vrednost;

public:
    Argument(string i, Tip t, T v) : Parametar(i, t), vrednost(v) {}
    virtual std::ostream &print(std::ostream &os)
    {
        Parametar::print(os);
        return os << "=" << vrednost;
    }
};

#endif