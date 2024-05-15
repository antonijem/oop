#include "letnja.hpp"

bool Letnja::odgovarajucaDubina()
{
    if (dohvatiDubinu() < 1.6)
        return false;
    return true;
}