#include "zimska.hpp"

bool Zimska::odgovarajucaDubina()
{
    if (dohvatiDubinu() < 4)
        return false;
    return true;
}