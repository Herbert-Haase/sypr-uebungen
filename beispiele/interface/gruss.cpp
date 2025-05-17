/*
 * gruss.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 12.8.2020
 */

#include "gruss.h"

gruss::gruss(uhr *u)
: u(u)
{ }

std::string gruss::gruessen()
{
    unsigned stunde;
    unsigned minute;

    this->u->ablesen(stunde, minute);

    if (6 <= stunde && stunde < 11)
    {
        return "Guten Morgen";
    }

    if (11 <= stunde && stunde < 18)
    {
        return "Guten Tag";
    }

    if (18 <= stunde && stunde <= 23)
    {
        return "Guten Abend";
    }

    throw std::string("Nachtruhe!");
}

