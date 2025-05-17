/*
 * testuhr.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 11.12.2024
 */
#include "testuhr.h"

testuhr::testuhr()
: stunde(0), minute(0)
{ }

void testuhr::stellen(unsigned s, unsigned m)
{
    this->stunde = (s + m / 60) % 24;
    this->minute = m % 60;
}

void testuhr::ablesen(unsigned& s, unsigned& m) const
{
    s = this->stunde;
    m = this->minute;
}

