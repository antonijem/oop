#include "figura.hpp"

Figura &Figura::operator=(Figura &fig)
{
    if (this != &fig)
    {
        this->centar = fig.centar;
        this->polja = fig.polja;
    }
    return *this;
}

bool Figura::gadjanje(Polje *p)
{
    if (p == centar)
    {
        delete centar;
        return true;
    }
    else
    {
        for (int i = 0; i < polja.dohvatiBrojElemenata(); i++)
        {
            if (p == polja[i])
            {
                delete polja[i];
                return true;
            }
        }
    }
    return false;
}

bool Figura::operator&(Figura &fig)
{
    if (*centar == *fig.centar)
    {
        return true;
    }
    for (int i = 0; i < polja.dohvatiBrojElemenata(); i++)
    {
        for (int j = 0; j < fig.dohvatiPolja()->dohvatiBrojElemenata(); j++)
        {
            if (*polja[i] == *(*fig.dohvatiPolja())[j])
            {
                return true;
            }
        }
    }

    for (int i = 0; i < fig.dohvatiPolja()->dohvatiBrojElemenata(); i++)
    {
        if (*centar == *(*fig.dohvatiPolja())[i])
        {
            return true;
        }
    }

    for (int i = 0; i < polja.dohvatiBrojElemenata(); i++)
    {
        if (*fig.centar == *polja[i])
        {
            return true;
        }
    }

    return false;
}

bool Figura::operator==(Figura &fig)
{
    if (dohvatiOznaku() == fig.dohvatiOznaku())
        return true;
    return false;
}
