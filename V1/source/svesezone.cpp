#include "svesezone.hpp"

bool SveSezone::odgovarajucaDubina()
{
    if (dohvatiDubinu() < 4)
        return false;
    return true;
}